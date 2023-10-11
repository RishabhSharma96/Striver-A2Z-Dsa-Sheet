class Solution {
public:
    string minWindow(string s, string t) {
        
        int i=0, j=0, n=s.size(), m=t.size(), length=INT_MAX, ansLeft=-1, ansRight=-1, have=0, need=m;
        unordered_map<char,int> sMap, tMap ;

        for(int k=0 ; k<m; k++){
            tMap[t[k]]++;
        }

        while(j<n){    
            sMap[s[j]]++;
            if(tMap.find(s[j]) != tMap.end() && sMap[s[j]] <= tMap[s[j]]){
                have++;
            }

            while(have == need){
                if(j-i+1 < length){
                    length = j-i+1;
                    ansLeft = i ;
                    ansRight = j;
                }
                sMap[s[i]]--;
                if(tMap.find(s[i]) != tMap.end() && sMap[s[i]] < tMap[s[i]]){
                    have--;
                }
                i++;
            }
            j++;
        }

        if(length == INT_MAX){
            return "";
        }

        string ans;
        for(int i=ansLeft; i<=ansRight; i++){
            ans.push_back(s[i]);
        }
        return ans ;
    }
};