//Set Matrix to Zero - Better and Optimal 
//Currently trying without seeing any solution in TUF
#include<bits/stdc++.h>
using namespace std;

void setMatrixZeroBetterSelf(vector<vector<int>>&matrix, int n, int m){
    vector<pair<int,int>> store;
    //Store the coordinates of the zeroes in pair in vector
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(matrix[i][j] == 0)
                {
                    pair<int,int>p(i,j);
                    store.push_back(p);
                }
        }
    }

    //Accessing the coordinates
    for(int i=0;i<store.size();i++){
        int row = store[i].first;
        int column = store[i].second;
        for(int j =0;j<n;j++){
            matrix[row][j] = 0;
        }
        for(int k=0;k<m;k++){
            matrix[k][column] = 0;
        }
    }
}

void displayMatrix(vector<vector<int>>matrix, int n, int m){
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            cout<<matrix[i][j]<<" ";
        }
        cout<<endl;
    }
}

void setMatrixZeroOptimal(vector<vector<int>>&matrix, int n,int m){
    //Step 1 Identify Row and column
    //row -> matrix[var][0]
    //col -> matrix[0][var]
    int col0 = 1;
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            //Step 2 Update the row and column in matrix
            if(matrix[i][j] == 0)
            {
                matrix[i][0] = 0;
                if(j !=0)
                    matrix[0][j] = 0;
                else
                    col0 = 0;
            }     
        }
    }

    //Step 3 Update the rest matrix to 0
    for(int i=1;i<n;i++){
        for(int j=1;j<m;j++){
            if(matrix[i][j] != 0){
                if(matrix[i][0] == 0 || matrix[0][j] == 0)
                    matrix[i][j] =0;
            }
        }
    }
    //Step 4 VVIP Update the row and column (col0) in matrix
    if(matrix[0][0] == 0)
        for(int j=0;j<n;j++){ //Updates horizontally  
            matrix[0][j] = 0;}
        
    if(col0==0){
        for(int i=0;i<n;i++){ //Updates vertically
            matrix[i][0] =0;
        }
    }
}


int main(){
    int n = 4, m = 4;
    vector<vector<int>>matrix = {{1,1,1,1},{1,0,1,1},{1,1,0,1},{0,1,1,1}};
    //Before Setting to zero
    displayMatrix(matrix,n,m);
    cout<<endl;
    //setMatrixZeroBetterSelf(matrix,n,m);
    //After Setting to zero
    //displayMatrix(matrix,n,m);
    //Optimal Solution
    setMatrixZeroOptimal(matrix,n,m);
    displayMatrix(matrix,n,m);
    return 0;
}

/*
Update - Checked Striver's Better approach - Similar to mine 
but I used a single vector instead of two separate arrays for rows and columns :)
*/