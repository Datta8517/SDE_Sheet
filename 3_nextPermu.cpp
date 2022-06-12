#include<bits/stdc++.h>
using namespace std;

void swap_element(vector<int> &nums, int st, int en){
	int temp = nums[st];
	nums[st]= nums[en];
	nums[en] = temp;
}

void reverseNums(vector<int> &nums, int st, int en){
	while(st<en)
		swap_element(nums, st++, en--);

}

void nextPermutation(vector<int>& nums) {

	int n = nums.size();
	int i,k;

	// to get the break point
	for(i=n-2; i>=0; i--){
		if(nums[i]<nums[i+1])
			break;
	}

	
	if(i>=0){	// if array is not in descending order
		for(k=n-1; k>i; k--){	// finding the element which is greater than ith element
			if(nums[k]>nums[i])
				break;
		}
		// now k is next largest first number
		swap_element(nums, i,k);	// swap ith and kth element
		
	}
	reverseNums(nums, i+1,n-1);	// after getting k on right position simply reverse the array from i+1 to n-1
	
        
}

int main(){
	vector<int> nums = {1,2,3,4,5};
	nextPermutation(nums);

	int n=nums.size();

	for(int i=0; i<n; i++){
		cout<<nums[i]<<" ";
	}
	cout<<"\n";


	return 0;
}