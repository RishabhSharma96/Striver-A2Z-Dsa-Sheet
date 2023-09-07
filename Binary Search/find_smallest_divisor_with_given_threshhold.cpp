class Solution {
public:
 
    int getMax(vector<int> & arr){
        int ans = INT_MIN ;

        for(int i=0 ; i<arr.size(); i++){
            if(arr[i] > ans){
                ans = arr[i];
            }
        }
        return ans;
    }

    long long helper(vector<int>& nums, int divisor){
        long long sum = 0;

        for(int i=0 ; i<nums.size() ; i++){
            sum += ceil((double)nums[i]/(double)divisor);
        }

        return sum;
    }

    int smallestDivisor(vector<int>& nums, int threshold) {

        int n = nums.size();
        int ans = 0 ;

        int low = 1 , high = getMax(nums);

        while(low <= high){
            int mid = low + (high-low)/2;

            if(helper(nums,mid) <= threshold){
                high = mid-1;
                ans = mid ;
            }
            else{
                low = mid+1 ;
            }
        }

        return ans;

    }
};