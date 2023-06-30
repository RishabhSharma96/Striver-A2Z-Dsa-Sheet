class Solution {
public:
    bool search(vector<int>& nums, int target) {
        int n = nums.size() ;
        int i=0 , j=n-1;
        
        while(i<=j){

            int mid = i + (j-i)/2;
            
            if(nums[mid] == target){
                return true;
            }

            else if(nums[i] == nums[mid] && nums[mid] == nums[j]){
                j--;
                i++;
            }

            else{
                if(nums[i] <= nums[mid]){
                    if(target >= nums[i] && target <= nums[mid]){
                        j = mid-1;
                    }
                    else{
                        i = mid+1;
                    }
                }
                else{
                    if(target >= nums[mid] && target <= nums[j]){
                        i = mid+1;
                    }
                    else{
                        j = mid-1;
                    }
                }
            }
        }

        return false;
    }
};