//
// Created by fluffy on 5/1/23.
//
#include <iostream>
#include <fstream>


int err_file(const char *err, const char *filename) {
	std::cout << "[ERROR] failed to " << err << " " << filename << std::endl;
	return (1);
}

int main(int argc, char *argv[]) {

	if (argc != 4) {
		std::cout << "[ERROR] bad arg <filename> <s1> <s2>" << std::endl;
		return (1);
	}

	const std::string inFileName	= argv[1];
	const char *s1					= argv[2];
	const char *s2					= argv[3];

	// Open <filename> and check
	std::fstream sourceFile;
	sourceFile.open(inFileName.c_str(), std::fstream::in);
	if (!sourceFile || !sourceFile.is_open()) {
		return (err_file("open", inFileName.c_str()));
	}

	
	// Create <filename>.replace and check
	const std::string outFileName = inFileName + ".replace";
	std::fstream outFile;

	outFile.open(outFileName.c_str(), std::fstream::out | std::fstream::trunc);
	if (!outFile || !outFile.is_open()) {
		return (err_file("create", outFileName.c_str()));
	}

	std::streambuf * sourceBuf = sourceFile.rdbuf();
	while (sourceBuf->sgetc() != EOF)
	{
		// Get the current character and advence position
		char ch = sourceBuf->sbumpc();

		// Check fo s1 occurence.
		if (s1[0] == ch) {

			int index = 1;
			// Buff use when we check the s1 occurence, store the current char
			// in the buff.
			std::string buff;
			buff += ch;

			while (sourceBuf->sgetc() != EOF && s1[index])
			{
				// Check the next current character
				const char currentChar = sourceBuf->sbumpc();
				// Store each character in the buffer, if the occurence check
				// fail we need to push the read character.
				buff += currentChar;

				if (currentChar != s1[index]) {
					// Check if the stream is open
					if (!outFile.is_open()) {
						sourceFile.close();
						return(err_file("write in", outFileName.c_str()));
					}

					// Write the read character while the check and clear the
					// buffer.
					outFile << buff;
					break;
				}
				index ++;
			}

			// If we reatch the \0 of the s1 that mean all charachter of the
			// string occurred
			if (!s1[index]) {
				// Check if the stream is open
				if (!outFile.is_open()) {
					sourceFile.close();
					return(err_file("write in", outFileName.c_str()));
				}
				// Write the replacement string
				outFile << s2;
				// break;
			}
			buff.clear();
			continue;
		}

		// Check if the stream is open
		if (!outFile.is_open()) {
			sourceFile.close();
			return(err_file("write in", outFileName.c_str()));
		}
		// Write the character
		outFile << ch;
	}

	sourceFile.close();
	outFile.close();
	return (0);
}