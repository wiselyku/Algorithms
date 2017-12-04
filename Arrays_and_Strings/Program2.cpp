#include<iostream>
using namespace std;

bool permutation(string s, string t){
    if(s.length()!= t.length()){
        return false;
    }
    int letters[128]={0};
    for(int i=0;i<s.length();i++){
        letters[s[i]] = letters[s[i]]+1;
    }
    for(int i=0;i<t.length();i++){
        letters[t[i]] = letters[t[i]]-1;
        if(letters[t[i]]<0){
            return false;
        }
    }
    return true;
}


int main(){
string s, t;
cin>>s>>t;
if(permutation(s,t)){
    cout<<"Yes, "<<endl;
}else{
    cout<<"No, "<<endl;
}

return 0;
}

