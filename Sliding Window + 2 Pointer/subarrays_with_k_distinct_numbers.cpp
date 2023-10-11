class Solution {

private:
    int helper(vector<int>& nums, int k){

        unordered_map<int,int> mp ;
        int i=0, j=0, n=nums.size(), count=0;

        while(j<n){
            mp[nums[j]]++;
            if(mp.size() <= k){
                count += j-i+1;
                j++;
            }
            else{
                while(i<=j && mp.size()>k){
                    mp[nums[i]]--;
                    if(mp[nums[i]] == 0){
                        mp.erase(nums[i]);
                    }
                    i++;
                }
                if(mp.size() <= k){
                    count += j-i+1;
                }
                j++;
            }
        }
        return count ;
    }

public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        // exact(k) = upto(k) - upto(k-1)
        return helper(nums,k) - helper(nums,k-1);
    }
};