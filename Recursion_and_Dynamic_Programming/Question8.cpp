#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

map<char, int> buildFreqTable(string s){
    map<char, int> mymap;
    for(int i=0;i<s.length();i++){
        map<char, int>::iterator iter;
        iter = mymap.find(s.at(i));
        if(iter == mymap.end()){
           // cout<<s.at(i)<<"";
            mymap.insert(pair<char, int>(s.at(i), 0));
        }
        mymap[s.at(i)]++;
    }
    return mymap;
}

void printPerms(map<char, int> mymap, string prefix, int remaining, vector<string> &result){
    if(remaining==0){
        result.push_back(prefix);
        return;
    }

    for(std::map<char,int>::iterator it=mymap.begin(); it!=mymap.end(); ++it){
        int count = it->second;
        if(count >0){
            mymap[it->first] = count -1;
            printPerms(mymap, prefix + it->first, remaining-1, result);
            mymap[it->first] = count;
        }
    }
}

int main(){
    string str = "aaabb";
    vector<string> result;
    map<char, int> mymap = buildFreqTable(str);
    printPerms(mymap, "", str.length(), result);
    for(int i=0; i<result.size();i++){
        cout<<result[i]<<endl;
    }
    return 0;
}

