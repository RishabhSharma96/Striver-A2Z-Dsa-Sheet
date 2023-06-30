// WITHOUT EXTRA SPACE
class Solution {
public:
    int romanToInt(string s) {
        long long ans = 0 ;
        for(int i=0 ; i<s.size() ; i++){
            if(s[i] == 'I'){
                ans = ans+1 ;
            }
            else if(s[i] == 'V'){
                if(i-1>=0 && s[i-1] == 'I'){
                    ans = ans + 5 - 2;
                }
                else{
                    ans = ans + 5;
                }
            }
            else if(s[i] == 'X'){
                if(i-1>=0 && s[i-1] == 'I'){
                    ans = ans + 10 - 2;
                }
                else{
                    ans = ans + 10;
                }
            }
            else if(s[i] == 'L'){
                if(i-1>=0 && s[i-1] == 'X'){
                    ans = ans + 50 - 20;
                }
                else{
                    ans = ans + 50;
                }
            }
            else if(s[i] == 'C'){
                if(i-1>=0 && s[i-1] == 'X'){
                    ans = ans + 100 - 20;
                }
                else{
                    ans = ans + 100;
                }
            }
            else if(s[i] == 'D'){
                if(i-1>=0 && s[i-1] == 'C'){
                    ans = ans + 500 - 200;
                }
                else{
                    ans = ans + 500;
                }
            }
            else if(s[i] == 'M'){
                if(i-1>=0 && s[i-1] == 'C'){
                    ans = ans + 1000 - 200;
                }
                else{
                    ans = ans + 1000;
                }
            }
        }
        return (int)ans;
    }
};


// WITH MAP
class Solution {
public:
    int romanToInt(string s) {
        long long ans = 0 ;

        unordered_map <char,int> chars{
            {'I',1},
            {'V',5},
            {'X',10},
            {'L',50},
            {'C',100},
            {'D',500},
            {'M',1000}
        };

        for(int i=0 ; i<s.size() ; i++){
            
            if(i-1>=0 && chars[s[i]] > chars[s[i-1]]){
                ans += (chars[s[i]] - 2*chars[s[i-1]]) ;
            }
            else{
                ans += chars[s[i]];
            }

        }
        return (int)ans;
    }
};