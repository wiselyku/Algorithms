#include<iostream>
using namespace std;

int min(int a, int b){
    if(a< b){
        return a;
    }else{
        return b;
    }
}

int max(int a, int b){
    if(a > b){
        return a;
    }else{
        return b;
    }
}

int magicFast(int arr[], int start, int end){
    if(end<start){
        return -1;
    }
    int midIndex = (start + end)/2;
    int midValue = arr[midIndex];
    if(midIndex==midValue){
        return midIndex;
    }
    // Search left
    int leftIndex = min(midIndex-1, midValue);
    int left = magicFast(arr, start, leftIndex);
    if(left>=0){
        return left;
    }

    // Search right
    int rightIndex = max(midIndex+1, midValue);
    int right = magicFast(arr, rightIndex, end);

    return right;

}


int main(){
    int arr[10]={-1,1,1,2,2,4,4,4,7,8};
    int hasMagic;
    hasMagic = magicFast(arr,0,9);
    if(hasMagic!=-1){
        cout<<"There exists a magic index and the index is "<<hasMagic<<endl;
    }else{
        cout<<"There does not exist a magic index"<<endl;
    }
    return 0;
}

