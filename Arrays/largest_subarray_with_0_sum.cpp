/*You are required to complete this function*/

class Solution{
    public:
    int maxLen(vector<int>&arr, int n){   
        
        int len=0;
        long long sum = 0;
        unordered_map<int,int> mp ; // for {cummulative_sum, at_what_index_that_sum_is}
        
        for(int i=0 ; i<n ; i++){
            sum += arr[i] ;
            if(sum == 0){
                len = i+1; 
            }
            else{
                if(mp.find(sum) != mp.end()){
                    len = max(len, abs(i-mp[sum]));
                }
                else{
                    mp[sum] = i;
                }
            }
        }
        return len ;
    }
};