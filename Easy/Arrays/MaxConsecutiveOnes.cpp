/*
count the max consecutive ones in the arr
*/

// easy approach o(N)
// scan from left to right, and keep local and max.Then update max when < local_max. return max

int findMaxConsecutiveOnes(vector<int>& nums) {

        int local_max = 0;
        int ans = INT_MIN;
        for(int i=0;i<nums.size();i++){
            
            if(nums[i] != 1)
                local_max = 0;
            else
                local_max++;
            if(local_max > ans)
                ans = local_max;
        }
        return ans;
}