class Solution {
public:
    int singleNonDuplicate(vector<int>& nums) {
        int low = 0;
        int high = nums.size() -1;
        int mid=0 ;

        while(low<=high){
            mid = low + (high - low)/2;
            int element = nums[mid] ;

            if((mid-1>=0 && nums[mid-1] != element) && 
            (mid+1<nums.size() && nums[mid+1] != element)){
                return nums[mid] ;
            }
            
            if(mid%2 == 0){
                if(mid+1<nums.size() && nums[mid+1] != element){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
            else{
                if(mid-1>=0 && nums[mid-1] != element){
                    high=mid-1;
                }
                else{
                    low=mid+1;
                }
            }
        }

        return nums[mid];

    }
};