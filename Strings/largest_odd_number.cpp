class Solution {
public:
    string largestOddNumber(string num) {

        int endIndex = -1 ;
        for(int i=num.size()-1; i>=0 ; i--){
            if(int(num[i]) % 2 == 1){
                endIndex=i ;
                break ;
            }
        }

        int popped = num.size()-endIndex-1;

        while(popped--){
            num.pop_back() ;
        }

        return num;
    }
};