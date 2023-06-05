#include<bits/stdc++.h>
using namespace std;

void markRow(vector<vector<int>>&matrix, int row,int m){
    for(int i=0;i<m;i++){
        if(matrix[row][i] !=0)
            matrix[row][i] = -1;
    }
}

void markColumn(vector<vector<int>>&matrix, int column, int n){
    for(int i=0;i<n;i++){
        if(matrix[i][column] != 0)
            matrix[i][column] = -1;
    }
}


void transformMatrix(vector<vector<int>>&matrix, int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j] == -1)
                matrix[i][j] = 0;
        }
    }
}

void displayMatrix(vector<vector<int>> matrix, int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<matrix[i][j]<<" ";
        }
    cout<<endl;
}
}


//Brute Force Approach 
void bruteForceApproach(vector<vector<int>>&matrix, int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j] == 0)
            {
                markRow(matrix,i,m);
                markColumn(matrix,j,n);
            }
        }
    }
    transformMatrix(matrix,n,m);
    displayMatrix(matrix,n,m);
}

//Time Complexity O(N*3)

int main()
{
    //Set Matrix zero
    int n = 3, m = 3;
    vector<vector<int>>matrix = {{0,1,1},{1,0,1},{1,1,1}};
    bruteForceApproach(matrix,n,m);
}