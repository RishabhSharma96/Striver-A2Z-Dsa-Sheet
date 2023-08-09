class Solution {
public:

    bool isPallindrome(string s,int l,int r){
        if(l>=r) return true;
        if(s[l] != s[r]) return false;
        return isPallindrome(s,l+1,r-1);
    }

    void solve(string s,vector<vector<string>>& ans,vector<string>& part,int index){
        if(index == s.size()){
            ans.push_back(part);
            return;
        }

        for(int i=index;i<s.size() ; i++){
            if(isPallindrome(s,index,i)){
                part.push_back(s.substr(index,i-index+1));
                solve(s,ans,part,i+1) ;
                part.pop_back();
            }
        }
    }

    vector<vector<string>> partition(string s) {
        
        vector<vector<string>> ans;
        vector<string> part;

        solve(s,ans,part,0) ;

        return ans ;
    }
};