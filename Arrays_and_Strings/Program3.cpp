#include<iostream>
#include<string>
#include <stdlib.h>
using namespace std;
// we assume the string length is 10
void replaceSpaces(string str, int trueLength){
    int spaceCount =0, index, i=0;
    for(int i=0; i<trueLength; i++){
        if(str[i]==' '){
            spaceCount++;
        }
    }
    cout<<"space count="<<spaceCount<<endl;
    index = trueLength + spaceCount*2;
    int index2 = index;
    cout<<"index="<<index<<endl;
    cout<<"string length="<<str.length()<<endl;
    char *str2;
    str2 = (char*) malloc(index+1);

    for(int i=trueLength-1; i>=0; i--){
        if(str[i]==' '){
            str2[index-1] = '0';
            str2[index-2] = '2';
            str2[index-3] = '%';
            index = index-3;

        }else{
            str2[index - 1] = str[i];
            index--;

        }
    }
    for(int i=0; i<index2; i++){
        cout<<str2[i];
    }

}


int main(){
    char str[100];
   // cin>>str;
    cin.getline(str,sizeof(str));
    replaceSpaces(str, 10);
    return 0;
}

