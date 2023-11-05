class Solution {
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        
        vector<vector<int>> ans ;
        int n = nums.size() ;

        for(int i=0 ; i < (1<<n) ; i++){
            vector<int> temp ;

            for(int bitcnt = 0 ; bitcnt<n ; bitcnt++){
                if(i&(1<<bitcnt)){
                    temp.push_back(nums[bitcnt]);
                }
            }
            ans.push_back(temp);
        }
        return ans ;
    }
};