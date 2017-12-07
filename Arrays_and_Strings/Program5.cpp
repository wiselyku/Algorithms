#include<iostream>
#include<string>
#include <stdlib.h>
using namespace std;

bool oneEditAway(string first, string second){
    if(abs(first.length() - second.length())){
        return false;
    }

    string s1 = first.length() < second.length() ? first : second;
    string s2 = first.length() < second.length() ? second : first;

    int index1 = 0;
    int index2 = 0;
    bool foundDifference = false;
    while(index2 < s2.length() && index1 < s1.length()){
        if(s1[index1]!=s2[index2]){
            if(foundDifference) return false;
            foundDifference = true;
            if(s1.length()==s2.length()){
                index1++;
            }
        }else{
            index1++;
        }
        index2++;
    }
    return true;
}


int main(){

string first, second;
cin>>first;
cin>>second;
if(oneEditAway(first, second)){
    cout<<"Yes"<<endl;
}else{
    cout<<"No"<<endl;
}

}

