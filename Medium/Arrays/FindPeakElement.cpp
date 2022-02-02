/*
find any peak element in the nums that is strictly greater than its neighbors in O(N) & O(LogN)
*/

//easy approach O(N)
// just scan from left, if we find any element greater than adjacents then return that index

int peakElement(int arr[], int n)
{
   for(int i=0;i<n;i++){
       if(i == 0){
           if(arr[i]>arr[i+1])
            return i;
       }
       else if(i==n-1){
           if(arr[i]>arr[i-1])
            return i;
       }
       else{
           if(arr[i]>arr[i+1]&&arr[i]>arr[i-1])
                return i;
       }
   }
   return 0;
}

//Medium approach O(Log N)
//binary search approach, check if mid is that element, if not only travel towards the greater element from the mid

int peak(int i, int j, vector<int> &nums){
    //checking all edge cases
        if(i==j)    //for single element
            return i;
        if(j-i==1){     //for 2 elements
            if(nums[i]>nums[j])
                return i;
            else
                return j;
        }

        //for >3 elements 
        int mid = (i+j)/2;
        
        if(nums[mid]>nums[mid-1]&& nums[mid]>nums[mid+1])
            return mid;    
        
        else if(nums[mid]<nums[mid-1])    //go towards left of mid
            return peak(i,mid-1,nums);
        
        else                                //go towards right of mid
            return peak(mid+1,j,nums);
        
    }
    
    int findPeakElement(vector<int>& nums) {
        return peak(0,nums.size()-1,nums);
    }