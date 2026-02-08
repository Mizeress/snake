#ifndef APPLES_HPP
#define APPLES_HPP

#include <utility>
using namespace std;

namespace AppleNS {

    class Apple {
        pair<int, int> position;
        char appleChar = 'O';

        public:
            Apple();
            pair<int, int> getPosition();
            char getAppleChar();

    };

}

#endif // APPLES_HPP