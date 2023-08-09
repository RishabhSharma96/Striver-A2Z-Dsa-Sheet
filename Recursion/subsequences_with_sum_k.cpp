class Solution{
    public:
    
    bool solve(vector<int> & arr, int size, int index, int sum){
        if(sum == 0){
            return true ;
        }
        
        if(index == size){
            return false ;
        }
        
        int take = solve(arr,size,index+1,sum-arr[index]);
        int nottake = solve(arr,size,index+1,sum);
        return take || nottake;
    }
    
    bool checkSubsequenceSum(int n, vector<int>& arr, int k) {
        return solve(arr,n,0,k);
    }
};