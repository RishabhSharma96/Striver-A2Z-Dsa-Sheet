//User function Template for C++

class Solution{
public:
    void maxHeapify(vector<int> &arr,int i,int n){
        int left=2*i+1;
        int right=2*i+2;
        int large=i;
        
        if(left<n && arr[left]>arr[large]){
            large=left;
        }
        if(right<n && arr[right]>arr[large]){
            large=right;
        }
        if(large!=i){
            swap(arr[large],arr[i]);
            maxHeapify(arr,large,n);
        }
    }
    void convertMinToMaxHeap(vector<int> &arr, int N){
        
        for(int i=N-1/2;i>=0;i--){
            maxHeapify(arr,i,N);
        }
    }
    
};