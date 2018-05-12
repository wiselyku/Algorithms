#include <iostream>
#include <vector>
#include <list>
#include <utility>          // for std::pair<>
#include <iomanip>          // for std::setw()
#include <string>
#include <map>
using namespace std;

void build_dictionary(vector<string> &book, map<string, int> &dictionary){
    std::map<string, int>::iterator it;
    int temp=0;
    for(int i=0;i<book.size();i++){

        it = dictionary.find(book[i]);
        if(it!=dictionary.end()){
            // 已經存在dictionary 所以要update
            temp = it->second;
            it->second = temp+1;
        }else{
            // 在dictionary 內尚未有 所以要insert
            dictionary.insert(std::pair<string,int>(book[i],1));
        }
    }

}



int main(){
vector<string> book;
book.push_back("hello");
book.push_back("world");
book.push_back("wisely");
book.push_back("how");
book.push_back("are");
book.push_back("you");
book.push_back("hello");
book.push_back("hello");
book.push_back("hello");
string str="hello";
map<string, int> dictionary;
build_dictionary(book, dictionary);

std::map<string, int>::iterator it;
it = dictionary.find(str);
        if(it!=dictionary.end()){
            cout<<"the word 【"<<str<< "】 exists "<<it->second<<" times"<<endl;
        }else{
            cout<<"not exist the word."<<endl;
        }

return 0;
}

