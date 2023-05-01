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

    const std::string fileName =  argv[1];
//    const char *s1       =  argv[2];
//    const char *s2       =  argv[3];

    // Open <filename> and check
    std::fstream sourceFile;
    sourceFile.open(fileName.c_str(), std::fstream::in);
    if (!sourceFile || !sourceFile.is_open()) {
        return (err_file("open", fileName.c_str()));
    }

    int nb = 0;
    std::streambuf * pbuf = sourceFile.rdbuf();
    while ( pbuf->sgetc() != EOF )
    {
        char ch = pbuf->sbumpc();
        (void)ch;
        nb++;
//        std::cout << ch;
    }
    std::cout << nb << std::endl;
    // Create <filename>.replace and check
    const std::string outFileName = fileName + ".replace";
    std::fstream outFile;

    outFile.open(outFileName.c_str(), std::fstream::out | std::fstream::app);
    if (!outFile || !outFile.is_open()) {
        return (err_file("create", fileName.c_str()));
    }


    sourceFile.close();
//    sourceFile
    return (0);
}