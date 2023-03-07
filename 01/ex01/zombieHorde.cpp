//
// Created by fluffy on 3/4/23.
//

#include "Zombie.hpp"

/**
 *
 * @param N Number of Zombie
 * @param name used to name the zombie
 * @return Address from the firs zombie of the array
 */
Zombie *Zombie::zombieHorde(int N, std::string name) {
    Zombie *allocZombie = new Zombie[N] ;

    if (!allocZombie)
        return (NULL);

    this->horde = allocZombie;
    this->hordeSize = N;

    for (int i = 0; i < N; ++i) {
        allocZombie[i].name = name;
    }

    return allocZombie;
}