//
// Created by fluffy on 2/23/23.
//

#include "Zombie.hpp"

int main(void) {

    const int N = 23;

    Zombie door = Zombie();
    Zombie * zombieHorde = door.zombieHorde(N, "UwU");

    for (int i = 0; i < N; ++i) {
        zombieHorde[i].announce();
        delete &zombieHorde[i];
    }

}