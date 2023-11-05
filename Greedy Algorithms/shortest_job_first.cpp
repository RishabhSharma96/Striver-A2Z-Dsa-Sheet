// User function Template for C++
// Back-end complete function Template for C++

class Solution {
  public:
    long long solve(vector<int>& bt) {
        
        int n = bt.size() ;
        sort(bt.begin(), bt.end());
        
        int long long wt=0, sum=0 ;
        // adding cummulative sum 
        for(int i=0; i<n-1; i++){
            wt += bt[i] ;
            sum += wt;
        }
        
        return sum/n ;
    }
};