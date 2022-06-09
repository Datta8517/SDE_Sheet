#include<bits/stdc++.h>
using namespace std;

void setZeroes(vector<vector<int>> &matrix){
	int rows = matrix.size();	// no. of rows in matrix
	int cols = matrix[0].size();	// no. of coloumns in matrix

	bool col= 1;

	for(int i=0; i<rows; i++){
		// checking weather 0th colm contain 0 value or not
		if(matrix[i][0]==0)
			col=0;

		// checking the presence of 0 at matrix[i][j]
		for(int j=1; j<cols; j++){
			if(matrix[i][j]==0){
				matrix[i][0]=0;
				matrix[0][j]=0;
			}
		}
	}


	// Now iterating matrix in reverse direction to check weather col or row has 0 or not

	for(int i=rows-1; i>=0; i--){
		for(int j=cols-1; j>=1; j--){
			if(matrix[i][0]==0 || matrix[0][j]==0)
				matrix[i][j]=0;
		}

		if(col==0){
			matrix[i][0]=0;
		}
	}
}

int main() {

  vector<vector<int>> arr;
  arr = {{1,1,1},{1,0,1},{1,1,1}};

  setZeroes(arr);
  cout<<"Output Matrix is "<<endl;
  for (int i=0; i <arr.size(); i++) {
    for (int j=0; j< arr[0].size(); j++) {
      cout <<arr[i][j]<< " ";
    }
    cout <<endl;
  }
}
