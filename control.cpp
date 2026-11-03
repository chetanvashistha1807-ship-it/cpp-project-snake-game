#include <iostream>
#include<conio.h>

using namespace std;

int main(){
    char direction  = 'U';
    
    char key = _getch();
    

    if(key=='w'){
        direction = 'U';
    } else if(key=='a'){
        direction ='L';
    } else if(key=='s'){
        direction = 'D';
    } else if(key=='d'){
        direction = 'R';
    } else if(key=='X')break;

    cout<<direction;

    return 0;
}