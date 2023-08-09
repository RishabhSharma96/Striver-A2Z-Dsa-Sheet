class Solution {
public:

    void solve(vector<vector<int>> & ans, vector<int> & helper, vector<int> & nums, int index, int target){
        if(target == 0){
            ans.push_back(helper);
            return ;
        }

        if(index == nums.size()){
            return ;
        }

        helper.push_back(nums[index]);
        if(nums[index] <= target){
            solve(ans,helper,nums,index,target-nums[index]);
        }
        helper.pop_back() ;
        solve(ans,helper,nums,index+1,target);
    }

    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> ans;
        vector<int> helper ;
        solve(ans,helper,candidates,0,target);
        return ans;
    }
};