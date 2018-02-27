#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
#include <stack>
using namespace std;

class Tower{

public:
    Tower(){

    }
    Tower(int i){
       // disks = new stack<int>;
        index1 = i;
    }

    int index(){
        return index1;
    }

    void add(int d){
        if(!disks.empty() && disks.top()<=d){
            cout<<"Error placing disk"<<d<<endl;
        }else{
            cout<<" add "<<d<<" to index "<<index1<<endl;
            disks.push(d);
        }
    }

    void moveTopTo(Tower &t){
        int top = disks.top();
        disks.pop();
        t.add(top);
    }

    void moveDisks(int n, Tower &destination, Tower &buffer){
        if(n>0){
            moveDisks(n-1, buffer, destination);
            cout<<"move "<<disks.top()<<" from index "<<index1;
            moveTopTo(destination);
            buffer.moveDisks(n-1, destination, *this);

        }

    }
private:
    stack<int> disks;
    int index1;
};



int main(){
    int n =3;
    Tower towers1 = Tower(0);
    Tower towers2 = Tower(1);
    Tower towers3 = Tower(2);

    for(int i=n-1;i>=0;i--){
        towers1.add(i);
    }
    towers1.moveDisks(n, towers3,towers2);
    return 0;
}

