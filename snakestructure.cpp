
#include <iostream>
using namespace std;

struct coordinates {
    int x;
    int y;
};

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

    // Displaying snake coordinates

    cout << "Snake Length: " << snakeLength << endl;

    for(int i = 0; i < snakeLength; i++) {

        if(i == 0)
            cout << "Head: ";
        else if(i == snakeLength - 1)
            cout << "Tail: ";
        else
            cout << "Body: ";

        cout << "(" << snake[i].x << ", "
             << snake[i].y << ")" << endl;
    }

    return 0;
}
