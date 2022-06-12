#include<bits/stdc++.h>
using namespace std;


// Kadene's algorithm to find max sum of subarray
long long maxSubarraySum(int arr[], int n)
{	// in this algorithm we skip the -ve sum and go forward
    long long  sum =0;
    long long  maxi = INT_MIN;
    
    for(int i=0; i<n; i++){
        sum+=arr[i];
        
        if(sum<0)
            sum=0;
        maxi = max(maxi, sum);
    }
    
    return maxi;
}

int main(){
	int n;
	cin>>n;

	int arr[n];
	for(int i=0; i<n; i++){
		int x;
		cin>>x;
		arr[i]=x;
	}

	long long ans = maxSubarraySum(arr, n);
	cout<<ans<<endl;

	return 0;

}