class Solution {
public:
    string removeKdigits(string num, int k) {
        
        if(num.size() == k){
            return "0" ;
        }

        int n = num.size();
        stack<char> s ;

        for(int i=0 ; i<n ; i++){
            while(!s.empty() && k>0 && num[i] < s.top()){
                s.pop();
                k--;
            }
            if(s.empty() && num[i] == '0') continue;
            s.push(num[i]);
        }

        while(k != 0 && !s.empty()){
            s.pop();
            k--;
        }

        string ans = "";

        while(!s.empty()){
            ans += s.top();
            s.pop();
        }

        reverse(ans.begin() , ans.end());
        return ans!="" ? ans : "0";
    }
};