class Solution {
public:

    string shortestCommonSupersequence(string str1, string str2) {
        int len1 = str1.size();
        int len2 = str2.size();

        vector<vector<int>> dp (len1+1 , vector<int> (len2+1, 0));

        for(int index1=1; index1<=len1 ; index1++){
            for(int index2=1; index2<=len2 ; index2++){

                if(str1[index1-1] == str2[index2-1]){
                    dp[index1][index2] = (1 + dp[index1-1][index2-1]);
                }
                else{
                    dp[index1][index2] = max(dp[index1][index2-1], dp[index1-1][index2]) ;
                }
            }
        }

        string lcs;
        int i = len1, j = len2;
        
        while (i > 0 && j > 0) {
            if (str1[i - 1] == str2[j - 1]) {
                lcs.push_back(str1[i-1]);
                i--;
                j--;
            }
            else if (dp[i-1][j] > dp[i][j-1]){
                lcs.push_back(str1[i-1]);
                i--;
            }
            else {
                lcs.push_back(str2[j-1]);
                j--;
            }
        }

        while(i > 0){
            lcs.push_back(str1[i-1]);
            --i;
        }
        
        while(j > 0){
            lcs.push_back(str2[j-1]);
            --j;
        }
        
        reverse(lcs.begin(), lcs.end());
        
        return lcs;

    }
};