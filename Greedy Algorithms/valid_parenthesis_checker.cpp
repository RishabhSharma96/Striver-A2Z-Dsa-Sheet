class Solution {
public:
    bool checkValidString(string s) {
        stack<char> star, open ;

        for(int i=0 ; i<s.size() ; i++){
            if(s[i] == '('){
                open.push(i);
            }
            else if(s[i] == '*'){
                star.push(i);
            }
            else{
                if(open.empty() == true && star.empty() == true){
                    return false;
                }
                else if(!open.empty()){
                    open.pop();
                }
                else{
                    star.pop();
                }
            }
        }
        
        while(!open.empty()){
            if(star.empty()){
                return false;
            }
            else if(open.top() < star.top()){
                open.pop();
                star.pop();
            }
            else{
                return false;
            }
        }

        return true ;
    }
};