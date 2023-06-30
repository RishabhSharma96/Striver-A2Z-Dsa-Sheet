class Solution {
public:
    string reverseWords(string s) {
        string ans="" , temp="" ;

        for(int i=0; i<s.size(); i++){
            if(s[i] == ' '){
                if(temp.size() != 0){
                    ans = temp + " " + ans ;
                    temp = "";
                }
            }
            else{
                temp.push_back(s[i]);
            }
        }

        if(temp.size() != 0){
            ans = temp + " " + ans ;
        }

        ans.pop_back();

        return ans ;
    }
};