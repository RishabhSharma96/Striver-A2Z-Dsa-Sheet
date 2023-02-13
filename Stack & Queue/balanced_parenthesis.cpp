class Solution {
public:

    bool ismatch(char a , char b){
        if(a == '(' && b == ')'){
            return true ;
        }
        else if(a == '{' && b == '}'){
            return true ;
        }
        else if(a == '[' && b == ']'){
            return true ;
        }
        else{
            return false ;
        }
    }

    bool isValid(string s) {
        stack<char> a ;

        if(s.size() == 1){
            return false ;
        }

        for(int i=0 ; i<s.size() ; i++){

            if( ( s[i] == '(' ) || ( s[i] == '{' ) || ( s[i] == '[' ) ){
                a.push(s[i]);
            }

            else{
                if(a.empty() == false){
                char top = a.top();
                if(ismatch(top,s[i]) == true){
                    a.pop() ;
                }
                else{
                    return false ;
                    break ;
                }
                }
                else{
                    return false;
                }
            }
        }

        if(a.empty() == true){
            return true ;
        }
        else{
            return false ;
        }
    }
};