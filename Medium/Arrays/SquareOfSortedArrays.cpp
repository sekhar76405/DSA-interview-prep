/*
    Given an integer array nums sorted in non-decreasing order, 
    return an array of the squares of each number sorted in non-decreasing order.
*/

// Easy approach O(NlogN)
// simply square and sort / use hash arrays to sort

vector<int> sortedSquares(vector<int>& nums) {
        for(int i=0;i<nums.size();i++){
            nums[i] *= nums[i];
        }
        sort(nums.begin(),nums.begin() + nums.size());
        return nums;
    }

// Medium approach O(N)
// squares of the arr will be in the form of 2 sorted array. Use the algo for merging two sorted arrays
 
vector<int> sortedSquares(vector<int>& nums) {     
        int i = 0;
        int j = nums.size()-1;
        int k = nums.size()-1;
        vector<int> ans(nums.size(),0);
        while(i<=j){
            if(i == j){
                ans[k] = nums[i]*nums[i];
                break;
            }
            if(nums[i]*nums[i]>=nums[j]*nums[j]){
                ans[k] = nums[i]*nums[i]; k--; i++;
            }
            else{
                ans[k] = nums[j]*nums[j]; k--; j--;
            }
        }
        return ans;         
}