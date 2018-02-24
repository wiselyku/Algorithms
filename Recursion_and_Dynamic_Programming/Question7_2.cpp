#include <iostream>
#include <vector>
#include <string>

using namespace std;

string insertCharAt(string word, char c, int i){
    string start = word.substr(0,i);
    string end = word.substr(i);
    return start + c + end;
}

vector<string> getPerms(string remainder){
    int len = remainder.length();
    vector<string> result;
    if(len == 0){
        result.push_back("");
        return result;
    }

    for(int i=0;i<len; i++){
        string before = remainder.substr(0,i);
        string after = remainder.substr(i+1);
        vector<string> partials = getPerms(before+after);

        for(int j=0; j<partials.size();j++){
            result.push_back(remainder.at(i)+partials[j]);
        }
    }

    return result;

}



int main(){
    string str = "abcd";
    vector<string> perms = getPerms(str);
    for(unsigned i=0;i<perms.size();i++){
        cout<<i+1<<" : "<<perms[i]<<endl;
    }
    return 0;
}

