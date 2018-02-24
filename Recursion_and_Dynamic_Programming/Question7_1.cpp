#include <iostream>
#include <vector>
#include <string>

using namespace std;

string insertCharAt(string word, char c, int i){
    string start = word.substr(0,i);
    string end = word.substr(i);
    return start + c + end;
}

vector<string> getPerms(string str){
   if(str.empty()){
        vector<string> ret;
        ret.push_back("");
        return ret;
   };

    vector<string> permutations;
    if(str.length()==0){
        permutations.push_back("");
        return permutations;
    }

    char first = str.at(0);
    string remainder = str.substr(1);

    vector<string> words = getPerms(remainder);
    for(unsigned i=0;i<words.size();i++){
        for(unsigned j=0;j<=words[i].length();j++){
            string s = insertCharAt(words[i], first, j);
            permutations.push_back(s);
        }
    }
    return permutations;
}



int main(){
    string str = "abcd";
    vector<string> perms = getPerms(str);
    for(unsigned i=0;i<perms.size();i++){
        cout<<perms[i]<<endl;
    }
    return 0;
}

