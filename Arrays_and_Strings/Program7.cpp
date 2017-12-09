#include<iostream>
#include<string>
#include<vector>

using namespace std;

bool rotate(vector< vector<char> > matrix){

    int n = matrix.size();
    for(int layer=0; layer < n/2; layer++){
        int first = layer;
        int last = n-1-layer;
        for(int i=first; i<last; i++){
            int offset = i - first;
            int top = matrix[first][i];
            matrix[first][i] = matrix[last-offset][first];
            matrix[last-offset][first] = matrix[last][last-offset];
            matrix[last][last-offset] = matrix[i][last];
            matrix[i][last] = top;
        }
    }

    for(int i=0; i < n; i++){
        for(int j=0; j<n ; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }


    return true;
}



int main(){
int N;
cout<<"input a number N"<<endl;
cin>>N;
vector< vector<char> > matrix(N, vector<char>('a'));

cout<<"input NxN matrix"<<endl;

char input;

    for(int i=0; i < N; i++){
        for(int j=0; j<N ; j++){
            cin>>input;
            matrix[i][j] = input;
        }
    }

    for(int i=0; i < N; i++){
        for(int j=0; j<N ; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }


bool b = rotate(matrix);

return 0;
}

