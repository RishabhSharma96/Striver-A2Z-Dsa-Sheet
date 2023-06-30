class Solution {
public:
    string removeOuterParentheses(string s) {
        string ans ;
        int cnt=0 ;

        for(int i=0; i<s.size(); i++){
            if(s[i] == '('){
                if(cnt == 0){
                    cnt++ ;
                }
                else{
                    ans.push_back('(');
                    cnt++ ;
                }
            }
            else{
                if(cnt == 1){
                    cnt--;
                }
                else{
                    ans.push_back(')');
                    cnt--;
                }
            }
        }

        return ans ;

    }
};