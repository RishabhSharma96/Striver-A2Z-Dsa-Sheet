class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {

        int n = nums.size() ;
        int cnt=0 , ans=0 ;

        for(int i=0 ;i<n ; i++){

            if(nums[i] == 1){
                ans = max(++cnt,ans) ;
            }
            else{
                cnt=0 ;
            }
        }

        return ans ;
    }
};