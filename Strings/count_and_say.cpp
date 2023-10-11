class Solution {

private:
    string helper(int n){

        if(n == 1){
            return "1" ;
        }

        string prevNumString = helper(n-1);

        string temp="";

        for(int i=0;i<prevNumString.size();) {
            char ch = prevNumString[i];
            int cnt=0;
            while(prevNumString[i]==ch && i<prevNumString.size()) {
                cnt++;
                i++;
            }
            temp.push_back(cnt+'0');
            temp.push_back(prevNumString[i-1]);
        }

        return temp ;
    }

public:
    string countAndSay(int n) {
        return helper(n);
    }
};