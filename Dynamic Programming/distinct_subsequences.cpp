class Solution {
public:

    int solve(int sIndex, int tIndex, string s, string t, vector<vector<int>> & dp){

        if(tIndex == 0){
            return 1 ;
        }
        if(sIndex == 0){
            return 0 ;
        }

        if(dp[sIndex][tIndex] != -1){
            return dp[sIndex][tIndex];
        }

        if(s[sIndex-1] == t[tIndex-1]){
            return dp[sIndex][tIndex] = (solve(sIndex-1,tIndex-1,s,t,dp) +
            solve(sIndex-1,tIndex,s,t,dp));
        }
        else{
            return dp[sIndex][tIndex] = solve(sIndex-1,tIndex,s,t,dp);
        }

    }

    int numDistinct(string s, string t) {
        int slen = s.length();
        int tlen = t.length() ;

        // vector<vector<int>> dp(slen+1, vector<int>(tlen+1, -1));
        // return solve(slen,tlen,s,t,dp);

        vector<vector<double>> dp(slen+1, vector<double>(tlen+1, 0));

        for(int sIndex=0 ; sIndex<=slen; sIndex++){
            dp[sIndex][0] = 1;
        }

        for(int sIndex=1 ; sIndex<=slen; sIndex++){
            for(int tIndex=1 ; tIndex<=tlen; tIndex++){
                if(s[sIndex-1] == t[tIndex-1]){
                    dp[sIndex][tIndex] = dp[sIndex-1][tIndex-1] + dp[sIndex-1][tIndex];
                }
                else{
                    dp[sIndex][tIndex] = dp[sIndex-1][tIndex];
                }
            }
        }

        return dp[slen][tlen] ;
    }
};