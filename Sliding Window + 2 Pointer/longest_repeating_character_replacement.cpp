class Solution {
public:

    int getHigestCountInMap(unordered_map<char,int> & freq){
        int maxi = INT_MIN ;
        for(auto it : freq){
            maxi = max(maxi, it.second);
        }
        return maxi ;
    }

    int characterReplacement(string s, int k) {
        
        unordered_map<char,int> freq ;
        int i=0, j=0, maxLength=0, n=s.size() ;

        while(j<n){
            freq[s[j]]++;
            int maxOccuringCharacter = getHigestCountInMap(freq);

            if(j-i+1-maxOccuringCharacter <= k){
                maxLength = max(maxLength, j-i+1);
                j++;
            }
            else{
                freq[s[i]]--;
                i++;
                j++;
            }
        }
        return maxLength ;
    }
};