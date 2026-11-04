
#include <iostream>
#include <conio.h>
#include <cstdlib>
#include <windows.h>
#include<ctime>


using namespace std;

// Structure to store the coordinates of each snake segment
struct coordinates {
    int x;
    int y;
};

// Function to move the snake
// The entire array is passed by reference
void moveSnake(coordinates (&snake)[100], int snakelength, char direction) {

    // Move each body segment to the position of the segment ahead
    // Start from the tail to avoid overwriting coordinates
    for (int i = snakelength - 1; i > 0; i--) {
        snake[i].x = snake[i - 1].x;
        snake[i].y = snake[i - 1].y;
    }

    // Move the head according to the current direction
    if (direction == 'w') snake[0].y--;
    if (direction == 'a') snake[0].x--;
    if (direction == 's') snake[0].y++;
    if (direction == 'd') snake[0].x++;
}

// Game board dimensions
int height = 20;
int width = 40;


//Food
int foodX;
int foodY;

void generateFood(coordinates (&snake)[100], int snakelength){

    
    foodX = rand()%38 + 1;
    foodY = rand()%18 + 1;

    bool occupied = false;

    for(int i = 0; i<snakelength; i++){
        if(snake[i].x==foodX && snake[i].y==foodY)occupied = true;


    }
    
    if(occupied==true)generateFood(snake,snakelength);


}

int main() {

    // Initial snake length
    int snakelength = 3;

    // Array to store snake segments
    coordinates snake[100];

    // Initial snake position
    // Head is on the right, so it can move right initially
    snake[0].x = 5;
    snake[0].y = 3;

    snake[1].x = 4;
    snake[1].y = 3;

    snake[2].x = 3;
    snake[2].y = 3;

    // Controls whether the game continues running
    bool gameRunning = true;

    // Initial direction of the snake
    char direction = 'd';

    //food
    srand(time(0));
    generateFood(snake,snakelength);


    int score = 0;

    

    // Main game loop
    while (gameRunning) {

        // Check whether the player has pressed a key
        if (_kbhit()) {

            // Read the pressed key
            char key = _getch();

            // Exit the game if 'x' is pressed
            if (key == 'x') {
                gameRunning = false;
            }

            // Update direction if a valid movement key is pressed
            else if (key == 'w' || key == 'a' ||
                     key == 's' || key == 'd') {

                direction = key;
            }
        }

        // Stop the loop if the player requested to exit
        if (!gameRunning) {
            break;
        }

        
        //Preserving old tail coordinates
        int oldTailX = snake[snakelength - 1].x;
        int oldTailY = snake[snakelength - 1].y;
        // Move the snake in its current direction


        moveSnake(snake, snakelength, direction);
        
        //Wall game over condition:-
        if(snake[0].x == 0 || snake[0].x==width-1 ||snake[0].y==0 || snake[0].y == height-1){
            gameRunning = false;
            break;
        }
        //Self collision game over condition
        for(int i = 1; i<snakelength; i++){
            if(snake[0].x==snake[i].x && snake[0].y==snake[i].y){
                gameRunning = false;
                break;
            }
        }

        
        if(snake[0].x==foodX && snake[0].y==foodY){

            snake[snakelength].x = oldTailX;
            snake[snakelength].y = oldTailY;
            
            snakelength++;
            score++;
            generateFood(snake,snakelength);
        }
        
        
        
        // Clear the console before drawing the updated board
        system("cls");
        
        // Render the game board
        for (int i = 0; i < height; i++) {

            for (int j = 0; j < width; j++) {

                bool found = false;

                // Draw the boundary walls
                if (i == 0 || i == height - 1 ||
                    j == 0 || j == width - 1) {

                    cout << "#";
                }

                else {

                    // Check whether a snake segment occupies this cell
                    for (int k = 0; k < snakelength; k++) {

                        if (snake[k].x == j && snake[k].y == i) {
                            found = true;
                            break;
                        }
                    }

                    // Draw the snake or an empty cell
                    if (found == true) {
                        cout << "O";
                    } else if(j==foodX && i==foodY){cout<<"*";
                    }
                    else {
                        cout << " ";
                    }
                }
            }

            cout << endl;
        }

        cout<<"....................Score: "<<score<<"...........................";

        // Control the snake's movement speed (250 milliseconds)
        Sleep(250);
    }

    return 0;
}
