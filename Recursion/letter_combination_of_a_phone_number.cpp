class Solution {
public:

    void solve(vector<string> & ans, unordered_map<int,string> mp, string temp, int index, string & digits){

        if(index == digits.size()){
            ans.push_back(temp);
            return ;
        }

        int number = digits[index] - '0';
        string keypad = mp[number];
        for(int i=0 ; i<keypad.size() ; i++){
            solve(ans,mp,temp+keypad[i],index+1,digits);
        }

    }

    vector<string> letterCombinations(string digits) {
        vector<string> ans ;

        if(digits.size() == 0){
            return ans;
        }
        
        unordered_map<int,string> mp;
        mp[2] = "abc";
        mp[3] = "def";
        mp[4] = "ghi";
        mp[5] = "jkl";
        mp[6] = "mno";
        mp[7] = "pqrs";
        mp[8] = "tuv";
        mp[9] = "wxyz";

        solve(ans,mp,"",0,digits);
        return ans;
    }
};