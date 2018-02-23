#include<iostream>
using namespace std;

int countWays(int n, int memo[]){
    if(n < 0){
        return 0;
    }else if(n==0){
        return 1;
    }else if(memo[n]>-1){
        return memo[n];
    }else{
        memo[n] = countWays(n-1, memo) + countWays(n-2, memo) + countWays(n-3, memo);
        return memo[n];
    }

}

int main(){
    int num = 6;
    int memo[num+1];
    for(int i=0;i<num+1;i++){
        memo[i] = -1;
    }
    cout<<"There are "<<countWays(num, memo)<<" ways to hop the staircase"<<endl;

    return 0;
}

