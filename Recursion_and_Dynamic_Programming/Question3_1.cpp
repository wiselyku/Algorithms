#include<iostream>
using namespace std;

int magicSlow(int arr[], int size){
    for(int i=0;i<size;i++){
        if(arr[i]==i){
            return i;
        }
    }
    return -1;
}


int main(){
    int arr[6]={-1,0,1,2,3,5};
    int hasMagic;
    hasMagic = magicSlow(arr, 6);
    if(hasMagic!=-1){
        cout<<"There exists a magic index and the index is "<<hasMagic<<endl;
    }else{
        cout<<"There does not exist a magic index"<<endl;
    }
    return 0;
}
