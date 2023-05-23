class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        vector<int> ans(nums.size(), 0) ;
        int p = 0 ;
        int n = 1 ;

        int it = 0;

        while(it < nums.size()){
            if(nums[it] > 0){
                ans[p] = nums[it] ;
                p+=2 ;
            }
            else{
                ans[n] = nums[it] ;
                n+=2 ;
            }
            it++ ;
        }

        return ans ;
    }
};