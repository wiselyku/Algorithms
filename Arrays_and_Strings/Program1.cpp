#include<iostream>
//We assume that the character set is ASCII, so all the characters come from ASCII.
using namespace std;

bool isUniqueChars(string str){
    if(str.length()>128) return false;
    bool char_set[128] ={false};
    for(int i=0;i<str.length();i++){
        int val = str[i];
        if(char_set[val]){
            return false;
        }
        char_set[val] = true;
    }
    return true;
}

int main(){
string str;
cin>>str;
if(isUniqueChars(str)){
    cout<<"it is unique";
}else{
    cout<<"it is not unique";
}

return 0;
}

