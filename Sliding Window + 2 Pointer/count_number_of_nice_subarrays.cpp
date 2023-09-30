class Solution {
public:

    int solve(vector<int>& nums, int target){

        int i=0, j=0, n=nums.size(), odds=0, totalSubarrays=0 ;

        while(j<n){

            if(nums[j]&1){
                odds++;
            }    

            while(i<=j && odds > target){
                if(nums[i]&1){
                    odds--;
                }
                i++ ; 
            }

            totalSubarrays += j-i+1 ;
            j++;

        }
        return totalSubarrays;
    }

    int numberOfSubarrays(vector<int>& nums, int k) {
        // exact k ka matlab upto k and upto k-1 ka difference.
        return solve(nums,k) - solve(nums,k-1);
    }
};