// dutch national flag
#include<bits/stdc++.h>
using namespace std;

void swap(vector<int> &nums, int i, int j){
	int temp = nums[i];
	nums[i] = nums[j];
	nums[j] = temp;
}

void sortColors(vector<int>& nums) {

	// initialized low and mid at 0th pos and high ar last pos
	int low =0;
	int mid =0;
	int high = nums.size()-1;

	while(mid<=high){
		switch(nums[mid]){
			// to shift all the 0s left side of low pointer ie., nums[0,....,low-1]=0
			case 0:
				swap(nums, low++, mid++);
				break;

			// 1s set in between the low and high ie., nums[low,...,high]=1
			case 1:
				mid++;
				break;

			// to shift all the 2s right side of the high pointer ie., nums[high+1,..., n-1]=2
			case 2:
				swap(nums, mid, high--);
				break;
		}
	}
        
}

int main(){
	vector<int> nums = {2,0,2,1,1,0};

	sortColors(nums);

	for(int i=0; i<nums.size(); i++){
		cout<<nums[i]<<" ";
	}
	cout<<"\n";

	return 0;
}