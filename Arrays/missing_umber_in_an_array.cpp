class Solution {
public:
    int missingNumber(vector<int>& nums) {
        int r=0;
        for(int i=0 ; i<nums.size() ; i++){
            r=r^nums[i]^(i+1);
        }
        return r ;
    }
};