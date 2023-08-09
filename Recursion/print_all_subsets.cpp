class Solution {
public:

    void solve(vector<vector<int>> & ans, vector<int> & helper, vector<int> & nums, int index){
        if(index == nums.size()){
            ans.push_back(helper);
            return ;
        }

        helper.push_back(nums[index]);
        solve(ans,helper,nums,index+1);
        helper.pop_back();
        solve(ans,helper,nums,index+1);
    }

    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> ans;
        vector<int> helper ;
        solve(ans,helper,nums,0);
        return ans;
    }
};