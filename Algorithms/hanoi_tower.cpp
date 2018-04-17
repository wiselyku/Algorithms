#include <iostream>
#include <vector>
#include <list>
#include <utility>          // for std::pair<>
#include <iomanip>          // for std::setw()
#include <string>

using namespace std;

int hanoi(vector<int> &original, vector<int> &middle, vector<int> &destination, string &str1, string &str2, string &str3, int num){
    if(num==1){
        cout<<"move "<<original.back()<<" to the "<<str3<<endl;
        destination.push_back(original.back());
        original.pop_back();
        return 1;
    }else{

        int num1, num2;

        num1 = hanoi(original, destination, middle, str1, str3, str2, num-1);
        int temp = original.back();
        cout<<"move "<<temp<<" to the "<<str3<<endl;
        destination.push_back(temp);
        original.pop_back();
        num2 = hanoi(middle, original, destination, str2, str1, str3, num-1);
        return num1+1+num2;
    }
}




int main(){
    vector<int> original, middle, destination;
    string str1="original", str2="middle", str3="destination";
    original.push_back(5);
    original.push_back(4);
    original.push_back(3);
    original.push_back(2);
    original.push_back(1);

    cout<<"the total number of moves is "<<hanoi(original, middle, destination, str1, str2,str3, 5);

return 0;
}

