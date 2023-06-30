// space - O(26)

class Solution {
public:
    bool isAnagram(string s, string t) {

        if(s.size() != t.size()) return false;
        
        vector<int> freq(26,0);

        for(int i=0 ; i<s.size() ; i++){
            int index = s[i] - 'a';
            freq[index]++ ;
        }

        for(int i=0 ; i<t.size() ; i++){
            int index = t[i] - 'a';
            if(freq[index] == 0){
                return false;
            }
            freq[index]--;
        }

        return true;

    }
};

// space - O(1)

class Solution
{
    public:
    bool isAnagram(string a, string b){
        
        sort(a.begin(),a.end());
        sort(b.begin(),b.end());
        
        return a==b ;
        
    }

};