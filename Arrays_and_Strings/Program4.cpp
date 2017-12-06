#include<iostream>
#include<string>
using namespace std;
// we assume the input are all lower characters.

int toggle(int bitVector, int index){
    if(index<0) return bitVector;

    int mask = 1 << index;
    if((bitVector & mask) ==0 ){
        bitVector |= mask;
    }else{
        bitVector &= ~mask;
    }
    return bitVector;
}


int createBitVector(string str){
    int bitVector = 0;
    for(int i=0; i<str.length();i++){
        int x = (int)str[i] - 96;
        bitVector = toggle(bitVector, x);
    }
    return bitVector;

}

bool checkExactlyOneBitSet(int bitVector){
    int result = bitVector & (bitVector -1);
    if( (bitVector & (bitVector -1))==0 ){
        return 1;
    }else{
        return 0;
    }
}



int main(){
string str;
cin>>str;
int bitVector = createBitVector(str);
if(checkExactlyOneBitSet(bitVector)){
    cout<<"Yes"<<endl;
}else{
    cout<<"No"<<endl;
}

return 0;
}

