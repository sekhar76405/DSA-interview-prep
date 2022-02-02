/*
    Find the min and max element in the array
*/

// easy approach O(N)
// scan from left to right and store min, max
pair<long long, long long> getMinMax(long long a[], int n) {
    
    
    long long min = INT_MAX;
    long long max = INT_MIN;
    for(int i =0;i<n;i++){
        if(a[i]>max)
            max = a[i];
        if(a[i]<min)
            min = a[i];
    }
    return {min,max};
}