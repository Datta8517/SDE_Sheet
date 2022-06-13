#include<bits/stdc++.h>
using namespace std;

// rotate matrix by 90 degree in cloclwise direction
// void rotate(vector<vector<int>>& matrix) {

// 	for(int i=0; i<matrix.size(); i++){
// 		for(int j=i; j<matrix[0].size(); j++){
// 			int temp = matrix[i][j];
// 			matrix[i][j] = matrix[j][i];
// 			matrix[j][i] = temp;
// 		}
// 	}

// 	for(int i=0; i<matrix.size(); i++){
// 		for(int j=0; j< matrix[0].size()/2; j++){
// 			int temp = matrix[i][j];
// 			matrix[i][j] = matrix[i][matrix[0].size()-1-j];
// 			matrix[i][matrix[0].size()-1-j] = temp;
// 		}
// 	}
        
// }





//	rotate each element of the matrix by one in clockwise direction
void rotate(vector<vector<int>> &matrix, int n, int m){

	int row_st =0;
	int col_st = 0;
	int prev, curr;

	while(row_st<n && col_st<m){

		// check weather row or col is not at the out of bound pos
		if(row_st + 1==n || col_st+1  ==m)
			break;

		// store 1st prev element of the matrix is mat[1][0]
		prev = matrix[row_st+1][col_st];

		// iterate matrix from top left to right
		for(int i=col_st; i<m; i++){
			curr = matrix[row_st][i];
			matrix[row_st][i] = prev;
			prev = curr;
		}
		row_st++;

		// iterate matrix from top right to bottom
		for(int i=row_st; i<n; i++){
			curr = matrix[i][m-1];
			matrix[i][m-1] = prev;
			prev = curr;
		}
		m--;

		// iterate matrix from bottom right to left
		if(row_st<n){
			for(int i=m-1; i>=col_st; i--){
				curr = matrix[n-1][i];
				matrix[n-1][i] = prev;
				prev=curr;
			}
		}
		n--;

		// iterate matrix from bottom left to top
		if(col_st<m){
			for(int i=n-1; i>=row_st; i--){
				curr = matrix[i][col_st];
				matrix[i][col_st] = prev;
				prev = curr;
			}
		}
		col_st++;

	}
}

int main(){
	vector<vector<int>> matrix = {{1,2,3},{4,5,6},{7,8,9}};

	rotate(matrix,3,3);

	for(auto it: matrix){
		for(auto i: it){
			cout<<i<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";

	return 0;
}