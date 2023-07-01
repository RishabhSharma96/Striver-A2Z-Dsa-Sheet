// USING STACK ->
class Solution {
public:
    int minAddToMakeValid(string s) {
        stack<char> st ;

        st.push(s[0]);

        for(int i=1 ; i<s.size() ; i++){

            if(!st.empty() && st.top() == '(' && s[i] == ')'){
                st.pop();
            }
            else{
                st.push(s[i]);
            }
        }
        return st.size();
    }
};

// WITHOUT STACK -> 
class Solution {
public:
    int minAddToMakeValid(string s) {
        int open = 0 , close = 0 ;

        for(int i=0 ; i<s.size() ; i++){

            if(s[i] == '('){
                open++ ;
            }
            else if(open>0 && s[i] == ')'){
                open-- ;
            }
            else if(s[i] == ')'){
                close++;
            }
            
        }

        return (open+close);
    }
};