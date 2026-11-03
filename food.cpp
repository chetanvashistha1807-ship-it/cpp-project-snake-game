#include<iostream>
#include<cstdlib>
#include<ctime>

using namespace std;


int main(){
    srand(time(0));
    int foodX = rand() % 38 + 1;
    int foodY = rand() % 18 + 1;

    cout<<foodX<<" "<<foodY;

    return 0;

}
