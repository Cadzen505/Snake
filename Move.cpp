#include "Move.h"

Move::Move(Direction dir) : direction(dir) {}

Direction Move::getDirection() const {
    return direction;
}

int Move::getDX() const {
    switch(direction) {
        case Direction::LEFT:  return -1;
        case Direction::RIGHT: return  1;
        default:               return  0;
    }
}

int Move::getDY() const {
    switch(direction) {
        case Direction::UP:   return -1;
        case Direction::DOWN: return  1;
        default:              return  0;
    }
}