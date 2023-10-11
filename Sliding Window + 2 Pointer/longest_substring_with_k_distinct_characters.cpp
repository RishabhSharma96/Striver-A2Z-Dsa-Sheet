//User function template for C++

class Solution{
  public:
    int longestKSubstr(string s, int k) {
        
        unordered_map<char,int> mp ;
        int i=0, j=0, n=s.size(), ans=INT_MIN ;
        
        while(j<n){
            
            mp[s[j]]++;
            
            if(mp.size() < k){
                j++;
            }
            else if(mp.size() == k){
                ans = max(ans , j-i+1);
                j++;
            }
            else{
                while(mp.size() > k){
                    mp[s[i]]--;
                    if(mp[s[i]] == 0){
                        mp.erase(s[i]);
                    }
                    i++;
                }
                if(mp.size() == k){
                    ans = max(ans , j-i+1);
                }
                j++;
            }
        }
        return ans == INT_MIN ? -1 : ans ;
    }
};