#include<iostream>
#include<vector>

using namespace std;

void rotate(vector< vector<int> > matrix, int m, int n){
    bool rowHasZero = false;
    bool colHasZero = false;

    for(int j=0; j< n; j++){
        if(matrix[0][j] == 0){
            rowHasZero = true;
            break;
        }
    }

    for(int j=0; j< m; j++){
        if(matrix[j][0] == 0){
            colHasZero = true;
            break;
        }
    }

    for(int i=1; i<m; i++){
        for(int j=1; j<n; j++){
            if(matrix[i][j]==0){
                matrix[i][0] = 0;
                matrix[0][j] = 0;
            }
        }
    }

    for(int i=1; i< m; i++){
        if(matrix[i][0]==0){
            for(int j=1; j<n ; j++){
                matrix[i][j] = 0;
            }
        }
    }

    for(int i=1; i< n; i++){
        if(matrix[0][i]==0){
            for(int j=1; j<m ; j++){
                matrix[j][i] = 0;
            }
        }
    }

    if(rowHasZero){
        for(int j=0; j<n ; j++){
            matrix[0][j] = 0;
        }
    }

    if(colHasZero){
        for(int j=0; j<m ; j++){
            matrix[j][0] = 0;
        }
    }

    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }



}



int main(){

int m, n;
cout<<"please input the number of rows and columns"<<endl;
cin>>m;
cin>>n;
vector< vector<int> > matrix(m, vector<int>(n,0));
int num;
    for(int i=0; i < m; i++){
        for(int j=0; j<n; j++){
            cin>>num;
            matrix[i][j] = num;
        }
    }
    for(int i=0; i<m; i++){
        for(int j=0; j<n; j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }

rotate(matrix, m, n);
return 0;
}

