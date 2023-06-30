class Solution {
public:
    int maxDepth(string s) {
        int ans=0 ; int incLength=0 ;
        for(int i=0 ; i<s.size() ; i++){
            if(s[i] == '('){
                incLength++;
            }
            else if(s[i] == ')'){
                incLength-- ;
            }
            ans = max(ans,incLength);
        }
        return ans;
    }
};