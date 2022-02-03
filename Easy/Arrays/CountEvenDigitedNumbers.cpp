/*
    Given an array nums of integers, return how many of them contain an even number of digits.
*/

int findNumbers(vector<int>& nums) {
        int ans = 0;
        string temp = "";
        for(int i=0;i<nums.size();i++){
            temp = "";
            temp = to_string(nums[i]);
            if(temp.length() %2==0)
                ans++;
            
            
        }
        return ans;
}