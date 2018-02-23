#include<iostream>
using namespace std;

int minProduct(int smaller, int bigger){
    if(smaller ==0){
        return 0;
    }
    else if(smaller == 1){
        return bigger;
    }
    int s = smaller >> 1;
    int halfProd = minProduct(s, bigger);

    if(smaller %2 == 0){
        return halfProd + halfProd;
    }else{
        return halfProd + halfProd + bigger;
    }

}


int main(){
    int a = 15, b=30;
    int bigger = a < b?b:a;
    int smaller = a<b?a:b;
    int result = minProduct(smaller, bigger);
    cout<<"a x b= "<<result<<endl;
    return 0;
}

