#include "Snake.h"

Snake::Snake(int start_x, int start_y) {
    body.push_back({start_x, start_y});
    body.push_back({start_x - 1, start_y});
}

void Snake::move(const Move& move_dir, bool grow_snake) {
    std::pair<int, int> new_head = {
        body[0].first + move_dir.getDX(),
        body[0].second + move_dir.getDY()
    };

    body.insert(body.begin(), new_head);

    if (!grow_snake) {
        body.pop_back();
    }
}

bool Snake::checkSelfCollision() const {
    std::pair<int, int> head = body[0];
    for (size_t i = 1; i < body.size(); ++i) {
        if (body[i] == head) {
            return true;
        }
    }
    return false;
}

std::pair<int, int> Snake::getHead() const {
    return body[0];
}

const std::vector<std::pair<int, int>>& Snake::getBody() const {
    return body;
}