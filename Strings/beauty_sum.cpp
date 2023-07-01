// WITH HASHMAP
class Solution {
public:
    int beautySum(string s) {
        int n = s.size();
        int l = INT_MAX, h = INT_MIN, beauty = 0;

        for(int i=0 ; i<n; i++){
            map<char,int> mp ;
            
            for(int j=i; j<n ; j++){
                mp[s[j]]++;

                for(auto & it : mp){
                    l = min(l,it.second);
                    h = max(h,it.second);
                }

                beauty += (h-l);
                l = INT_MAX;
                h = INT_MIN;
            }
            mp.clear();
        }
        return beauty ;
    }
};