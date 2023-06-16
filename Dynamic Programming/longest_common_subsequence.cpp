class Solution {
public:

    int solve(string text1, string text2, int index1, int index2, vector<vector<int>> & dp){

        if(index2 == 0){
            return 0;
        }

        if(index1 == 0){
            return 0 ;
        }

        if(dp[index1][index2] != -1){
            return dp[index1][index2] ;
        }

        if(text1[index1-1] == text2[index2-1]){
            return dp[index1][index2] = (1 + solve(text1,text2,index1-1,index2-1,dp));
        }

        return dp[index1][index2] = 
        max(solve(text1,text2,index1-1,index2,dp), solve(text1,text2,index1,index2-1,dp)) ;
    
    }

    int longestCommonSubsequence(string text1, string text2) {
        int len1 = text1.size();
        int len2 = text2.size();
        // vector<vector<int>> dp (len1+1 , vector<int> (len2+1, -1));
        // return solve(text1, text2, len1, len2, dp);

        vector<vector<int>> dp (len1+1 , vector<int> (len2+1, 0));

        for(int index1=1; index1<=len1 ; index1++){
            for(int index2=1; index2<=len2 ; index2++){

                if(text1[index1-1] == text2[index2-1]){
                    dp[index1][index2] = (1 + dp[index1-1][index2-1]);
                }
                else{
                    dp[index1][index2] = max(dp[index1][index2-1], dp[index1-1][index2]) ;
                }
            }
        }
        return dp[len1][len2];
    }
};