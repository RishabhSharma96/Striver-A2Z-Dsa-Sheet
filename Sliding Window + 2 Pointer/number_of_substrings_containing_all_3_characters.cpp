class Solution {
public:
    int numberOfSubstrings(string s) {
        
        int aCount=-1, bCount=-1, cCount=-1, substrings=0 ;
        int i=0 ;

        while(i<s.size()){
            if(s[i] == 'a'){
                aCount = i ;
            }
            else if(s[i] == 'b'){
                bCount = i ;
            }
            else if(s[i] == 'c'){
                cCount = i ;
            }

            substrings += min({aCount,bCount,cCount}) + 1;
            i++;
        }
        return substrings ;
    }
};