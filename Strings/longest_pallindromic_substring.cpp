class Solution {
public:
    string longestPalindrome(string s) {
        
        if(s.size() <= 1){
            return s ;
        }

        int n = s.size() ;
        int palStart=0, palEnd=0, maxLen=1 ;

        // odd pallindrome length present case :
        for(int i=0 ; i<n ; i++){
            int l=i, r=i ;
            while(l>=0 && r<n){
                if(s[l] == s[r]){
                    l--;
                    r++;
                }
                else{
                    break ;
                }
            }
            int length = r-l+1;
            if(length > maxLen){
                maxLen = length;
                palStart = l+1;
                palEnd = r-1;
            }
        }

        // even pallindrome length present case :
        for(int i=0 ; i<n ; i++){
            int l=i, r=i+1 ;
            while(l>=0 && r<n){
                if(s[l] == s[r]){
                    l--;
                    r++;
                }
                else{
                    break ;
                }
            }
            int length = r-l+1;
            if(length > maxLen){
                maxLen = length;
                palStart = l+1;
                palEnd = r-1;
            }
        }

        string pallindrome = "";

        for(int i=palStart; i<=palEnd ; i++){
            pallindrome += s[i];
        }

        return pallindrome;

    }
};