//User function template for C++

class Solution
{
  public:
  
    long long solve(string s , int k){
        long long int i=0, j=0, n=s.size(), count=0;
        unordered_map<char,long long> freq ;
        
        while(j<n){
            
            freq[s[j]]++;
            if(freq.size() > k){
                while(freq.size() > k){
                    freq[s[i]]--;
                    if(freq[s[i]] == 0){
                        freq.erase(s[i]);
                    }
                    i++;
                }
            }
            count += j-i+1;
            j++;
        }
        return count ;
    }
  
    long long int substrCount (string s, int k) {
        return (solve(s,k) - solve(s,k-1));
    }
};