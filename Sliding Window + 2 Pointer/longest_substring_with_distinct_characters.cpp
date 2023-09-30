class Solution {
public:

    int lengthOfLongestSubstring (string str){
    int n = str.size();
    int i = 0, j = 0;

    int ans = 0;

    map<char, int> freq;

    while(j < n) {

        freq[str[j]]++;

        if(freq.size() == j-i+1) {
            ans = max(ans, j-i+1);
            j++;
        }

        else if(freq.size() < j-i+1) {

            while(freq.size() < j-i+1) {
                freq[str[i]]--;
                if(freq[str[i]] == 0) {
                    freq.erase(str[i]);
                }
                i++;
            }
            if(freq.size() == j-i+1){
                ans = max(ans, j-i+1);
            }
            j++;
        }
    }
    return ans;
}

};