class Solution {
public:

    void solve(int index ,vector<int> & nums, vector<int>& helper, vector<vector<int>>& ans){

        ans.push_back(helper);

        for(int i=index ; i<nums.size() ; i++){

            if((i>index)&&(nums[i] == nums[i-1])){
                continue ;
            }

            helper.push_back(nums[i]);
            solve(i+1,nums,helper,ans) ;
            helper.pop_back() ;
        }
    }

    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        
        vector<int> helper ;
        vector<vector<int>> ans ;

        solve(0,nums,helper,ans);

        return ans ;

    }
};