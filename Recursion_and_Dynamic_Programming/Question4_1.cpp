#include<iostream>
#include<vector>
using namespace std;
// We use 0 to represent empty set, so if a set contains 0 and 1, that means this set contains 1. Because 0 means empty.
void powerSet(int n){
    vector< vector<int> > power_set;
    vector<int> empty_set;
    empty_set.push_back(0);
    power_set.push_back(empty_set);
    int size = power_set.size();
    for(int i=1; i<=n ; i++){
        size = power_set.size();
        // clone
        for(int j=0; j<size; j++){
           power_set.push_back(power_set[j]);

        }

        // add new
        for(int j=0; j<size; j++){
           power_set[j].push_back(i);

        }
    }

    size = power_set.size();
    int sub_size;
    for(int j=0; j<size; j++){
        sub_size = power_set[j].size();
        for(int k=0; k<sub_size; k++){
            cout<< power_set[j][k]<<",";
        }
        cout<<endl;
    }


}


int main(){
    powerSet(4);
    return 0;
}

