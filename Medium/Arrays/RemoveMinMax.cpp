/*
    Find min, max elemetns of arr return min deletions required 
    from frontside or backside to remove these min max
*/

// easy approach O(N)
// just scan and find min, max and thier indices. there are 3 ways to delete: del both from front, from back, both front and back
// return min of these 3 posibilities

int minimumDeletions(vector<int>& nums) {
        int min_val = INT_MAX;
        int max_val = INT_MIN;
        int min_ptr = 0, max_ptr = 0;
        for(int i=0;i<nums.size();i++){
            if(nums[i]>max_val){
                max_ptr = i;
                max_val = nums[i];
            }
            if(nums[i]<min_val){
                min_ptr = i;
                min_val = nums[i];
            }
        }
        int i = min(min_ptr,max_ptr);
        int j = max(min_ptr,max_ptr);
        int from_front = j+1;
        int from_back = nums.size() - i;
        int from_both = i+1 + nums.size()-j;
        
        int min_del = min(  min(from_front,from_back) , from_both  );
        return min_del;
}