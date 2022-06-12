#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> generate(int numRows) {
    vector<vector<int>> ans(numRows);

    for(int i=0; i<numRows; i++){

    	ans[i].resize(i+1);	//create size of the row 
    	ans[i][0] = ans[i][i]=1; // make leftmost and rightmost pos of each row 1

    	for(int j=1; j<i; j++){
    		ans[i][j] = ans[i-1][j-1] + ans[i-1][j];	// inner element is sum of upper two element
    	}
    }

    return ans;
}


int main(){

	vector<vector<int>> pascal = generate(5);

	for(auto i: pascal){
		for(auto j: i){
			cout<<j<<" ";
		}
		cout<<endl;
	}
	cout<<endl;
}