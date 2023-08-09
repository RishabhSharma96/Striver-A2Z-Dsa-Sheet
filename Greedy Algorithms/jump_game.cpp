class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size() ;

        int i=0 ;
        int reachability = 0;

        while(i < n){
            if(i > reachability){
                return false;
            }
            reachability = max(reachability , i+nums[i]);
            i++;
        }

        return true ;

    }
};