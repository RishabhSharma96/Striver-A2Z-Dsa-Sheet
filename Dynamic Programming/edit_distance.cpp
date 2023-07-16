class Solution {
public:

    int solve(string word1, string word2,int index1, int index2, vector<vector<int>> & dp){

        if(index1 == 0){
            return index2+1 ;
        }

        if(index2 == 0){
            return index1+1 ;
        }

        if(dp[index1][index2] != -1){
            return dp[index1][index2] ;
        }

        if(word1[index1-1] == word2[index2-1]){
            return dp[index1][index2] = solve(word1,word2,index1-1,index2-1,dp);
        }
        else{
            return dp[index1][index2] = 1 + (min(solve(word1,word2,index1-1,index2-1,dp) , 
            min(solve(word1,word2,index1,index2-1,dp) , 
            solve(word1,word2,index1-1,index2,dp))));
        }
    }

    int minDistance(string word1, string word2) {
        int len1 = word1.size() , len2 = word2.size() ;
        
        // vector<vector<int>> dp(len1+1, vector<int> (len2+1, -1));
        // return solve(word1,word2,len1,len2,dp)-1;

        vector<vector<int>> dp(len1+1, vector<int> (len2+1, -1));

        for(int index1=0; index1<=len2; index1++){
            dp[0][index1] = index1;
        }

        for(int index2=0; index2<=len1; index2++){
            dp[index2][0] = index2;
        }

        for(int index1=1; index1<=len1; index1++){
            for(int index2=1; index2<=len2; index2++){
                if(word1[index1-1] == word2[index2-1]){
                    dp[index1][index2] = dp[index1-1][index2-1];
                }
                else{
                    dp[index1][index2] = 1 + (min(dp[index1-1][index2-1], 
                    min(dp[index1][index2-1] , dp[index1-1][index2])));
                }
            }
        }

        return dp[len1][len2];
    }
};