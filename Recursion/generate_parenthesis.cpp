class Solution {
public:

    void solve(int open, int close, string helper, vector<string> & ans) {
        if(open == 0 && close == 0){
            ans.push_back(helper);
            return ;
        }

        if(open > 0){
            solve(open-1,close,helper+"(",ans);
        }

        if(open < close && close > 0){
            solve(open,close-1,helper+")",ans);
        }
    }

    vector<string> generateParenthesis(int n) {
        vector<string> ans ;
        solve(n,n,"",ans);
        return ans;
    }
};