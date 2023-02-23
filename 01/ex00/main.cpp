//
// Created by fluffy on 2/23/23.
//

#include "Zombie.hpp"

int main(void) {
    Zombie testConstructor = Zombie();
    Zombie* testAlloc = new Zombie();
    Zombie testRandom;
    Zombie *testNew = testRandom.newZombie("Billy");

    testConstructor.newZombie("Keven");
    testAlloc->newZombie("Mike");
    testRandom.randomChump("Lolo");
    delete testNew;
    delete testAlloc;
}