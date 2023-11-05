class Solution {
public:

    bool splitHelper(vector<int>& nums, int k, int allowedSum){

        int count=0, sum=0;

        for(int i=0 ; i<nums.size() ; i++){
            if(sum + nums[i] <= allowedSum){
                sum += nums[i] ;
            }
            else{
                count++;
                sum = nums[i];
            }
        }

        if(count >= k){
            return true;
        }
        return false;

    }

    int splitArray(vector<int>& nums, int k) {
        
        int n = nums.size();
        int maxi=INT_MIN, sum=0 ;

        for(auto it : nums){
            maxi = max(maxi,it);
            sum += it ;
        }

        int low = maxi , high = sum;

        while(low <= high){
            int mid = high - (high-low)/2;

            if(splitHelper(nums,k,mid)){
                low = mid+1;
            }
            else{
                high = mid-1;
            }
        }

        return low;

    }
};