#include<iostream>
using namespace std;

int magicFast(int arr[], int start, int end){
    if(end<start){
        return -1;
    }
    int mid = (start + end)/2;
    if(arr[mid]==mid){
        return mid;
    }else if(arr[mid]<mid){
        return magicFast(arr, mid+1,end);
    }else{
        return magicFast(arr, start,mid-1);
    }
}


int main(){
    int arr[6]={-1,0,1,2,3,5};
    int hasMagic;
    hasMagic = magicFast(arr,0,5);
    if(hasMagic!=-1){
        cout<<"There exists a magic index and the index is "<<hasMagic<<endl;
    }else{
        cout<<"There does not exist a magic index"<<endl;
    }
    return 0;
}

