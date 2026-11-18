#ifndef SNAKE_H
#define SNAKE_H

#include <vector>
#include <utility>
#include "Move.h"

class Snake {
public:
    Snake(int start_x, int start_y);
    
    void move(const Move& move_dir, bool grow_snake);
    bool checkSelfCollision() const;
    
    std::pair<int, int> getHead() const;
    const std::vector<std::pair<int, int>>& getBody() const;

private:
    std::vector<std::pair<int, int>> body;
};

#endif