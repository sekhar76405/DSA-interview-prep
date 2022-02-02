/*
The arr is in a mountain shape. Its starts increasing to a peak and then decreasing till end. Find the Peak 
*/

// Easy approach O(N)
// scan form left and return i where we encounter arr[i+1]>arr[i] first and break

int peakIndexInMountainArray(vector<int>& arr) {
        for(int i=0;i<arr.size()-1;i++){
            if(arr[i+1]<arr[i]){
                return i;
            }
        }
        return arr.size()-1;
}

// Easy Approach O(Log N)
// simple binary search, go towards greater peak and handle cases for single and doual elements
int peakIndexInMountainArray(vector<int>& arr) {
        int i = 0, j = arr.size()-1;
        
        while(i<=j){
            if(i == j)      //for single element
                return i;
            if(j-i == 1){      //for 2 elements
                if(arr[i]>arr[j])
                    return i;
                else
                    return j;
            }
            //for >3 elements
            int mid = (i+j)/2;
            if(arr[mid] > arr[mid-1] && arr[mid] > arr[mid+1])
                return mid;
            else if(arr[mid-1]>arr[mid])
                j = mid-1;
            else
                i = mid+1;
        }
        return 0;
    }