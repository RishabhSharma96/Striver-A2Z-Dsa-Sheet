class Solution{
    
    private:
    
    void merge(long long arr[], long long n, long long l, long long h, long long mid, long long int &count) {
    long long i = l;
    long long j = mid+1;
    vector<long long>v;
    
    while(i <= mid && j <= h) {
        if(arr[i]<=arr[j]) {
            v.push_back(arr[i]);
            i++;
        }
        else {
            count += mid-i+1;
            v.push_back(arr[j]);
            j++;
        }
    }
    
    while(i<=mid) {
        v.push_back(arr[i]);
        i++;
    }
    while(j<=h) {
        v.push_back(arr[j]);
        j++;
    }
    
    long long k = l;
    for(long long l = 0; l<v.size() ; l++) {
        arr[k++] = v[l];
    }
}

void merge_sort(long long arr[], long long n, long long l, long long h, long long int &count) {
    if(l<h) {
        int mid = (l+h)/2;
        merge_sort(arr,n,l,mid,count);
        merge_sort(arr,n,mid+1,h,count);
        merge(arr,n,l,h,mid,count);
    }
}
    
  public:
    // arr[]: Input Array
    // N : Size of the Array arr[]
    // Function to count inversions in the array.
    long long int inversionCount(long long arr[], long long N)
    {
        long long int count = 0;   
        merge_sort(arr,N,0,N-1,count);    
        return count;
    }

};