class Solution {
public:
    int jump(vector<int>& nums) {
        int reachabilityofIndex = 0;
        int jumpCount=0 ;
        int maxReachability = 0;
        int n = nums.size();
        int i=0 ;

        while(i < n-1){
            
            maxReachability = max(maxReachability , i+nums[i]);
            if(i == reachabilityofIndex){
                reachabilityofIndex = maxReachability;
                jumpCount++;
            }
            i++;
        }

        return jumpCount ;
    }
};