#include <iostream>
#include <vector>
#include <cstdlib>
#include "Snake.h"
#include "Move.h"

const int WIDTH = 10;
const int HEIGHT = 10;

void render(const Snake& snake, const std::pair<int, int>& food) {
    std::cout << "\033[2J\033[1H";

    for (int y = 0; y < HEIGHT; ++y) {
        for (int x = 0; x < WIDTH; ++x) {
            if (x == 0 || x == WIDTH - 1 || y == 0 || y == HEIGHT - 1) {
                std::cout << "#";
            } 
            
            else {

                bool is_body = false;
                if (snake.getHead().first == x && snake.getHead().second == y) {
                    std::cout << "O";
                    is_body = true;
                } 
                
                else {
                    for (const auto& segment : snake.getBody()) {
                        if (segment.first == x && segment.second == y) {
                            std::cout << "o";
                            is_body = true;
                            break;
                        }
                    }
                }

                if (!is_body) {
                    if (food.first == x && food.second == y) {
                        std::cout << "*";
                    } else {
                        std::cout << " "; 
                    }
                }
            }
        }
        std::cout << "\n";
    }
}

int main() {

    Snake snake(WIDTH/2, HEIGHT/2);
    
    std::pair<int, int> food = {std::rand() % (WIDTH - 2) + 1, std::rand() % (HEIGHT - 2) + 1};
    
    Direction current_dir = Direction::RIGHT;
    bool running = true;

    std::cout << "Controls: w (up), s (down), a (left), d (right), q (quit)\n";

    while (running) {
        render(snake, food);

        char input;
        std::cout << "Move (w/a/s/d/q): ";
        if (!(std::cin >> input)) break;

        if (input == 'q') {
            break;
        } 

        else if (input == 'w' && current_dir != Direction::DOWN) {
            current_dir = Direction::UP;
        } 
        
        else if (input == 's' && current_dir != Direction::UP) {
            current_dir = Direction::DOWN;
        } 
        
        else if (input == 'a' && current_dir != Direction::RIGHT) {
            current_dir = Direction::LEFT;
        } 
        
        else if (input == 'd' && current_dir != Direction::LEFT) {
            current_dir = Direction::RIGHT;
        }

        Move move(current_dir);
        bool grew = (snake.getHead().first + move.getDX() == food.first && 
                     snake.getHead().second + move.getDY() == food.second);

        snake.move(move, grew);

        if (grew) {
            food = {std::rand() % (WIDTH - 2) + 1, std::rand() % (HEIGHT - 2) + 1};
        }

        auto head = snake.getHead();
        if (head.first <= 0 || head.first >= WIDTH - 1 || head.second <= 0 || head.second >= HEIGHT - 1) {
            std::cout << "Game Over! You hit a wall.\n";
            running = false;
        }

        if (snake.checkSelfCollision()) {
            std::cout << "Game Over! You ran into yourself.\n";
            running = false;
        }
    }

    return 0;
}