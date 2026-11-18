#ifndef MOVE_H
#define MOVE_H

enum class Direction { UP, DOWN, LEFT, RIGHT };

class Move {
public:
    Move(Direction dir);
    
    Direction getDirection() const;
    int getDX() const;
    int getDY() const;

private:
    Direction direction;
};

#endif