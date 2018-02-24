#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

void addParen(vector<string> &list, int leftRem, int rightRem, char str[], int index){
    if(leftRem<0 || rightRem<leftRem){
        return;
    }

    if(leftRem==0 && rightRem==0){
        string temp_str(str);
        list.push_back(temp_str);
    }else{
        str[index] = '(';
        addParen(list, leftRem-1, rightRem, str, index+1);
        str[index] = ')';
        addParen(list, leftRem, rightRem-1, str, index+1);
    }
}


int main(){
    int count = 4;
    char str[4*2];
    vector<string> list;
    addParen(list, count, count, str, 0);
    for(int i=0;i<list.size();i++){
        cout<<list[i]<<endl;
    }
    return 0;
}

