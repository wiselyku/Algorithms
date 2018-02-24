#include <iostream>
#include <vector>

using namespace std;

void permutation(vector<int> &array, vector< vector<int> > &container, unsigned int start_idx, unsigned int array_size)
{
    if (start_idx == array_size - 1) {
        container.push_back(array);
        return;
    }

    for (int i = start_idx; i < array_size; i++) {
        swap(array[start_idx], array[i]);
        permutation(array, container, start_idx + 1, (unsigned int)array.size());
        swap(array[start_idx], array[i]);
    }
}

vector< vector<int> > permute(vector<int> &A) {
    vector< vector<int> > result;
    permutation(A, result, 0, (unsigned int)A.size());
    return result;
}



int main(){
    vector<int> permuation_array;
    permuation_array.push_back(1);
    permuation_array.push_back(2);
    permuation_array.push_back(3);
    permuation_array.push_back(4);
    vector< vector<int> > result = permute(permuation_array);
    for(int i=0; i<result.size();i++){
        for(int j=0;j<result[i].size();j++){
            cout<<result[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

