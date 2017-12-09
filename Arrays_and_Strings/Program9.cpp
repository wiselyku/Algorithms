#include<iostream>
#include<vector>
#include<string>

using namespace std;

bool isRotation(string str1, string str2){
    int len = str1.length();
    if(len==str2.length() && len >0){
        string ss = str1 + str1;
        int pos = ss.find(str2);
        if(pos==-1){
            return false;
        }else{
            return true;
        }
    }
    return false;
}


int main(){
    string str1, str2;
    cout<<"input two strings"<<endl;
    cin>>str1;
    cin>>str2;
    if(isRotation(str1,str2)){
        cout<<"Yes, they are rotations."<<endl;
    }else{
        cout<<"No, they are not rotations."<<endl;
    }

return 0;
}

