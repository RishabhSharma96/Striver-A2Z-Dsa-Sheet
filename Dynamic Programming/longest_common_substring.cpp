class Solution{
    public:
    
    int longestCommonSubstr (string text1, string text2, int n, int m)
    {
        int len1 = text1.size();
        int len2 = text2.size();

        vector<vector<int>> dp (len1+1 , vector<int> (len2+1, 0));

        for(int index1=1; index1<=len1 ; index1++){
            for(int index2=1;index2<=len2 ; index2++){

                if(text1[index1-1] == text2[index2-1]){
                    dp[index1][index2] = (1 + dp[index1-1][index2-1]);
                }
                else{
                    dp[index1][index2] = 0;
                }
            }
        }
        
        int maxLength = 0 ;
        for(int i=0 ; i<=len1; i++){
            for(int j=0 ; j<=len2; j++){
                maxLength = max(maxLength,dp[i][j]);
            }
        } 
        return maxLength;
    }
};