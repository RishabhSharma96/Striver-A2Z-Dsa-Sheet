class Solution {
public:

    int solve(vector<int>& nums, int target){

        int i=0, j=0, n=nums.size(), sum=0, totalSubarrays=0 ;

        while(j<n){

            sum += nums[j] ;    

            while(i<=j && sum > target){
                sum -= nums[i];
                i++ ; 
            }

            totalSubarrays += j-i+1 ;
            j++;

        }
        return totalSubarrays;
    }

    int numSubarraysWithSum(vector<int>& nums, int goal) {
        // exact n matlab upto n - upto n-1
        return abs(solve(nums,goal) - solve(nums,goal-1)) ;
    }
};