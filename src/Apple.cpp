#include <Apple.hpp>
#include <cstdlib> // for rand()
#include <ctime>   // for time()


namespace AppleNS {
    Apple::Apple() {
        //Seed random number generator
        srand(static_cast<unsigned int>(time(nullptr)));

        position.first = rand() % 36 + 2; // Random x position between 2 and 37
        position.second = rand() % 16 + 2; // Random y position between 2 and 17

        // Ensure apple is placed on an even x coordinate for better alignment with player movement
        if (position.first % 2 != 0) {
            position.first += 1;
        }

    }

    pair<int, int> Apple::getPosition() {
        return position;
    }

    char Apple::getAppleChar() {
        return appleChar;
    }
}