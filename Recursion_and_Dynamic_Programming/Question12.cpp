#include <iostream>
#include <vector>
#include <string>
#include <map>
#include <cmath>
using namespace std;
int GRID_SIZE = 8;

bool checkValid(int columns[], int row1, int column1){
    for(int row2=0;row2<row1;row2++){
        int column2 = columns[row2];
        if(column1 == column2){
            return false;
        }
        int columnDistance = abs(column2 - column1);
        int rowDistance = row1 - row2;
        if(columnDistance == rowDistance){
            return false;
        }
    }
    return true;
}

void placeQueens(int row, int columns[], vector< vector<int> > &results){
    if(row == GRID_SIZE){
        vector<int> temp_array;
        for(int i=0;i<GRID_SIZE;i++){
            temp_array.push_back(columns[i]);
        }
        results.push_back(temp_array);
    }else{
        for(int col=0;col<GRID_SIZE;col++){
            if(checkValid(columns, row, col)){
                columns[row] = col;
                placeQueens(row+1, columns, results);
            }
        }
    }
}


int main(){
    vector< vector<int> > results;
    int columns[GRID_SIZE];
    placeQueens(0, columns, results);
    cout<<"There are "<<results.size()<<" solutions"<<endl;
    for(int i=0;i<results.size();i++){
        cout<<"Solution "<<i+1<<":"<<endl;
        cout<<"  1,2,3,4,5,6,7,8,"<<endl;
        for(int j=0;j<GRID_SIZE;j++){
            cout<<j+1<<" ";
            for(int k=0;k<GRID_SIZE;k++){

                if(k!=results[i][j]){
                    cout<<" ,";
                }else{
                    cout<<"O,";
                }
            }
            cout<<endl;
            //cout<<results[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}

