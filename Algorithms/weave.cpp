#include <iostream>
#include <vector>
#include <list>
#include <queue>
using namespace std;
void weave(vector<int> &first, vector<int> &second, vector<int> &result){

    if(first.size()==0){

        for(int i=0;i<result.size();i++){
            std::cout<<result[i]<<" ";
        }

        for(int j=0;j<second.size();j++){
            std::cout<<second[j]<<" ";
        }
        std::cout<<std::endl;
        return;
    }else if(second.size()==0){
        for(int i=0;i<result.size();i++){
            std::cout<<result[i]<<" ";
        }
        for(int j=0;j<first.size();j++){
            std::cout<<first[j]<<" ";
        }
        std::cout<<std::endl;
        return;
    }

    for(int i=1; i<=2;i++){

        if(i==1){
            int temp = first[0];
            result.push_back(temp);
            first.erase(first.begin());
            weave(first, second, result);
            std::vector<int>::iterator it;
            it = first.begin();
            first.insert(it,temp);
            result.pop_back();
        }else{
            int temp = second[0];
            result.push_back(temp);
            second.erase(second.begin());
            weave(first, second, result);
            std::vector<int>::iterator it;
            it = second.begin();
            second.insert(it,temp);
            result.pop_back();
        }
    }
}


int main(){
    vector<int> first, second, result;
    first.push_back(1);
    first.push_back(2);
    second.push_back(3);
    second.push_back(4);
    second.push_back(5);
    weave(first, second, result);
    return 0;
}

