#ifndef PLAYER_HPP
#define PLAYER_HPP

#include <deque>
#include <utility>
using namespace std;

namespace PlayerNS {

    class Player {
        pair<int, int> position;
        int length = 2;
        char playerChar = '@';

        int moveDirection = 0; // default move direction is right

        deque<pair<int, int>> body; // to store the positions of the player's body segments

        public:
            void movePlayer();
            bool setMoveDirection(int newDirection);
            Player();
            pair<int, int> getPosition();
            char getPlayerChar();
            deque<pair<int, int>> getBody();
            void incrementLength() { length++; }
    };

}
#endif // PLAYER_HPP
