class Solution {
public:

    void solve(vector<vector<int>> & ans, vector<int> & helper, int counter, int digitCount, int sum){
        if(sum == 0 && digitCount == 0){
            ans.push_back(helper);
            return ;
        }

        if(counter > 9){
            return ;
        }

        helper.push_back(counter);
        solve(ans,helper,counter+1,digitCount-1,sum-counter);
        helper.pop_back();
        solve(ans,helper,counter+1,digitCount,sum);

    }

    vector<vector<int>> combinationSum3(int k, int n) {
        vector<vector<int>> ans;
        vector<int> helper ;
        solve(ans,helper,1,k,n);
        return ans;
    }
};