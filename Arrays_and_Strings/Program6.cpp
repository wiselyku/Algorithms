#include<iostream>
#include<string>
#include<vector>
#include <iomanip>
#include <locale>
#include <sstream>
using namespace std;

int countLength(int num){
    int length = 0;
    while(num!=0){
        length++;
        num = num/10;
    }
    return length;
}


int countCompression(string str){
    int compressedLength = 0;
    int countConsecutive = 0;

    for(int i=0;i<str.length();i++){
        countConsecutive++;
        if(i+1 >= str.length() || str[i]!=str[i+1]){
            compressedLength = compressedLength + 1 + countLength(countConsecutive);
            countConsecutive=0;
        }
    }
    return compressedLength;
}


int compress(string str){
    int finalLength = countCompression(str);
    if(finalLength>=str.length()){
        cout<<str<<endl;
        return 0;
    }


    vector<string> compressed;
    int countConsecutive = 0;
    string Result;
    string temp="a";
    for(int i=0;i<str.length();i++){
        countConsecutive++;
        if(i+1 >= str.length() || str[i]!=str[i+1]){
            temp[0] = str[i];
            temp[1] = '\0';
            compressed.push_back(temp);
            ostringstream convert;
            convert << countConsecutive;
            Result = convert.str();
            compressed.push_back(Result);
            countConsecutive=0;
        }
    }

    for(int i=0; i< compressed.size(); i++){
        cout<<compressed[i];
    }
    return 1;
}




int main(){
    string str;
    cin>>str;
    compress(str);
    return 0;
}

