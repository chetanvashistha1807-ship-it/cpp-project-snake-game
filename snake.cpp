#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <windows.h>

using namespace std;


int width = 50, height = 25;

struct coordinates {
    int x;
    int y;
};

void movement(char direction, coordinates &snake) {
    if(direction == 'U') snake.y--;
    if(direction == 'D') snake.y++;
    if(direction == 'L') snake.x--;
    if(direction == 'R') snake.x++;
}

int main() {

    coordinates snake[100];

    int snakeLength = 3;

    // Assigning coordinates
    snake[0].x = 5;
    snake[0].y = 3;

    snake[1].x = 4;
    snake[1].y = 3;

    snake[2].x = 3;
    snake[2].y = 3;

    bool gameRunning = true;
    char direction = 'R';

    // Displaying the board and snake
    while(gameRunning) {

        if(_kbhit()) {
            char key = _getch();

            if(key == 'w') {
                direction = 'U';
            }
            else if(key == 'a') {
                direction = 'L';
            }
            else if(key == 's') {
                direction = 'D';
            }
            else if(key == 'd') {
                direction = 'R';
            }
            else if(key == 'x') {
                gameRunning = false;
            }
        }

        if(!gameRunning) {
            break;
        }

        for(int i = snakeLength - 1; i > 0; i--) {
            snake[i].x = snake[i-1].x;
            snake[i].y = snake[i-1].y;
        }

        movement(direction, snake[0]);

        system("cls");

        for(int i = 0; i < height; i++) {

            for(int j = 0; j < width; j++) {

                bool found = false;

                // Checking boundary
                if(i == 0 || i == height - 1 ||
                   j == 0 || j == width - 1) {

                    cout << "#";
                }
                else {

                    // Checking whether the snake occupies this cell
                    for(int k = 0; k < snakeLength; k++) {

                        if(j == snake[k].x && i == snake[k].y) {
                            found = true;
                            break;
                        }
                    }

                    // Printing the snake or an empty cell
                    if(found == true) {
                        cout << "O";
                    }
                    else {
                        cout << " ";
                    }
                }
            }

            cout << endl;
        }

        Sleep(500);
    }

    return 0;
}