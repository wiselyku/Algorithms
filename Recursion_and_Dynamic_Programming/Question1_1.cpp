#include<iostream>
using namespace std;

int countWays(int n){
    if(n < 0){
        return 0;
    }else if(n==0){
        return 1;
    }else{
        return countWays(n-1) + countWays(n-2) + countWays(n-3);
    }

}

int main(){
    int num = 5;
    cout<<"There are "<<countWays(num)<<" ways to hop the staircase"<<endl;

    return 0;
}

