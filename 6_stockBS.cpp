#include<bits/stdc++.h>
using namespace std;

int maxProfit(vector<int>& prices) {
	
	int maxiProfit=0;
	int minPrice = INT_MAX;

	for(int i=0; i<prices.size(); i++){
		
			minPrice = min(minPrice, prices[i]);
		maxiProfit = max(maxiProfit, prices[i]-minPrice);
	}

	return maxiProfit;
}

int main(){

	vector<int> prices={7,1,5,3,6,4};

	int profit = maxProfit(prices);

	cout<<profit<<endl;

	return 0;
}