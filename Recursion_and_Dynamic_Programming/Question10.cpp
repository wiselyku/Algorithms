#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <stack>
using namespace std;

enum Color {Black, White, Red, Yellow, Green};
string color_array[5] = {"Black", "White", "Red", "Yellow", "Green"};
bool PaintFill(Color **screen, int r, int c, Color ocolor, Color ncolor, int size_r, int size_c){

    if( r<0 || r>= size_r || c<0 || c>size_c ){
        return false;
    }
    //cout<<" r="<<r<<" c="<<c<<endl;
    if(screen[r][c] == ocolor ){
       // cout<<color_array[screen[r][c]]<<" I am here r="<<r<<" c="<<c<<endl;
       // system("Pause");
        screen[r][c] = ncolor;
        PaintFill(screen, r-1, c, ocolor, ncolor, size_r, size_c);
        PaintFill(screen, r+1, c, ocolor, ncolor, size_r, size_c);
        PaintFill(screen, r, c-1, ocolor, ncolor, size_r, size_c);
        PaintFill(screen, r, c+1, ocolor, ncolor, size_r, size_c);


    }
    return true;
}


int main(){
    int size_r = 3, size_c = 3;
    Color *screen[3];
    for(int i=0;i<3;i++){
        screen[i] = new Color[3];
    }
    screen[0][0] = Color::Yellow;
    screen[0][1] = Color::Yellow;
    screen[0][2] = Color::White;
    screen[1][0] = Color::Black;
    screen[1][1] = Color::Yellow;
    screen[1][2] = Color::Yellow;
    screen[2][0] = Color::Yellow;
    screen[2][1] = Color::Yellow;
    screen[2][2] = Color::Yellow;

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<color_array[screen[i][j]]<<" ";
        }
        cout<<endl;
    }


    if(PaintFill(screen, 1, 1, Color::Yellow, Color::Red, size_r, size_c)){
        cout<<"------------------ paint fill is done -----------------"<<endl;
    }

    for(int i=0;i<3;i++){
        for(int j=0;j<3;j++){
            cout<<color_array[screen[i][j]]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

