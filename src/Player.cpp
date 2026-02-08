#include <deque>
#include <utility>

#include "Player.hpp"
using namespace std;


namespace PlayerNS {
    void Player::movePlayer() {
        switch (moveDirection) {
            case 0: // right
                position.first += 2;
                break;
            case 1: // down
                position.second += 1;
                break;
            case 2: // left
                position.first -= 2;
                break;
            case 3: // up
                position.second -= 1;
                break;
        }

        // Add new head position to the body
        body.push_front(position);

        // Remove tail if body exceeds length
        if (body.size() > length) {
            body.pop_back();
        }
    }

    bool Player::setMoveDirection(int newDirection) {
        if (newDirection >= 0 && newDirection < 4) {
            if ((moveDirection == 0 && newDirection == 2) || // right to left
                (moveDirection == 2 && newDirection == 0) || // left to right
                (moveDirection == 1 && newDirection == 3) || // down to up
                (moveDirection == 3 && newDirection == 1)) { // up to down
                return false; // prevent reversing direction
            }
            moveDirection = newDirection;
            return true;
        }

        return false; // invalid direction
    }

    Player::Player() {
        position.first = 10; // x position
        position.second = 10; // y position
    }

    pair<int, int> Player::getPosition() {
        return position;
    }

    deque<pair<int, int>> Player::getBody() {
        return body;
    }

    char Player::getPlayerChar() {
        return playerChar;
    }


    };
