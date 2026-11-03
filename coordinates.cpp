
#include<iostream>
using namespace std;

int width = 10;
int height = 6;

struct coordinates {
    int x;
    int y;
};

int main() {

    coordinates O;

    O.x = 3;
    O.y = 2;

    cout << "Initial Position:" << endl;
    cout << "X = " << O.x << endl;
    cout << "Y = " << O.y << endl;

    // Moving right
    O.x++;

    cout << "\nAfter moving right:" << endl;
    cout << "X = " << O.x << endl;
    cout << "Y = " << O.y << endl;

    return 0;
}
