#include<bits/stdc++.h>
using namespace std;

vector<vector<int>> merge(vector<vector<int>>& intervals) {

	vector<vector<int>> mergeInterval;

	if(intervals.size()==0)
		return mergeInterval;
    
    sort(intervals.begin(), intervals.end());
    
    // taking 1st pair from the intervals
    vector<int> tempInterval = intervals[0];

    for(auto it: intervals){	// merge two vector if they overlapped
    	if(it[0]<=tempInterval[1]){
    		tempInterval[1] = max(it[1], tempInterval[1]);
    	}
    	else{		// else push them in answer
    		mergeInterval.push_back(tempInterval);
    		tempInterval = it; // select next interval
    	}
    }
    mergeInterval.push_back(tempInterval);	// push the remaining vector in final answer

    return mergeInterval;
}

int main(){

	vector<vector<int>> intervals = {{1,3},{2,6},{8,10},{15,18}};

	vector<vector<int>> ans = merge(intervals);

	for(auto it:ans){
		for(auto i:it){
			cout<<i<<" ";
		}
		cout<<"\n";
	}
	cout<<"\n";

	return 0;
}