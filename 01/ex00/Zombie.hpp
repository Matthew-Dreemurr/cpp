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
    Zombie* newZombie( std::string name );
    void randomChump( std::string name );
private:
    std::string name;
    void announce( void );


};


#endif //CPP_ZOMBIE_HPP
