#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

int makeChange(int amount, int denoms[], int index, int array_length){

    if(index >= array_length-1){
        return 1;
    }
    int denomAmount = denoms[index];
    int ways = 0;
    for(int i=0;i*denomAmount<=amount;i++){
        int amountRemaining = amount -i*denomAmount;
        ways += makeChange(amountRemaining, denoms, index+1,4);
    }
    return ways;
}


int main(){
    int n=25;
    int array_length =4;
    int denoms[array_length] = {25,10,5,1};
    int result = makeChange(n,denoms,0, array_length);
    cout<<"The number of ways is "<<result<<endl;
    return 0;
}

