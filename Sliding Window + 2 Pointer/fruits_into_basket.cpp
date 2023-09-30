class Solution {
  public:
    int totalFruits(int n, vector<int> &fruits) {
        
        int i=0, j=0, fruitCount=0 ;
        unordered_map<int,int> mp ;
        
        while(j<n){
            
            mp[fruits[j]]++;
            
            if(mp.size() > 2){
                while(mp.size() > 2){
                    mp[fruits[i]]--;
                    if(mp[fruits[i]] == 0){
                        mp.erase(fruits[i]);
                    }
                    i++;
                }  
            }

            fruitCount = max(fruitCount, j-i+1);
            j++;
        }
        return fruitCount ;
    }
};