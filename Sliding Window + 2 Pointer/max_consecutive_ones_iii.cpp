class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        
        int i=0, j=0, zeroes=0, length=0, n=nums.size();

        while(j<n){

            if(nums[j] == 0){
                zeroes++;
            }

            while(zeroes > k){
                if(nums[i] == 0){
                    zeroes--;
                }
                i++;
            }
            
            length = max(length, j-i+1);
            j++;

        }
        return length;
    }
};