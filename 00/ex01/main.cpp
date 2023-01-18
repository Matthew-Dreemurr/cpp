
#include "iostream"
#include "PhoneBook.hpp"


int main(){
	PhoneBook phoneBook;
	do {
        if (!phoneBook.promptCommand()) {
            break ;
        }
	} while (1);
    return (0);
}