class Solution {
public:

    int lcs(string text1, string text2) {
        int len1 = text1.size();
        int len2 = text2.size();

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

    int minDistance(string word1, string word2) {
        int s11 = lcs(word1,word2);
        int s12 = lcs(word2,word1);

        return (word1.size() + word2.size() - s11 - s12);
    }
};