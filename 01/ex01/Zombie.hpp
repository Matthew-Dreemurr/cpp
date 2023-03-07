//
// Created by fluffy on 2/23/23.
//

#ifndef CPP_ZOMBIE_HPP
#define CPP_ZOMBIE_HPP

#include "iostream"


class Zombie {
public:
    Zombie();
    Zombie(const Zombie&);
    ~Zombie();

    Zombie &operator=(const Zombie&);
    void announce( void );
    Zombie* zombieHorde( int N, std::string name );
private:
    int         hordeSize;
    Zombie      * horde;
    std::string name;


};


#endif //CPP_ZOMBIE_HPP
