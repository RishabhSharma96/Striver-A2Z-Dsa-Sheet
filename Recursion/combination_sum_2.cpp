class Solution {
public:
    void solve(vector<vector<int>> & ans, vector<int> & helper, vector<int> & nums, int index, int target){
        if(target == 0){
            ans.push_back(helper);
            return ;
        }

        for(int i=index; i<nums.size() ; i++){
            if(i>index && nums[i] == nums[i-1]){
                continue ;
            }
            else if(nums[i] > target){
                break;
            }
            else{
                helper.push_back(nums[i]);
                solve(ans,helper,nums,i+1,target-nums[i]);
                helper.pop_back();
            }
        }
    }

    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {

        sort(candidates.begin() , candidates.end()); 

        vector<vector<int>> ans;
        vector<int> helper ;
        solve(ans,helper,candidates,0,target);

        return ans;
    }
};