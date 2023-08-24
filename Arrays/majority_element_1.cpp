class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int counter = 0;
        int element = nums[0] ;

        for(int i=0 ; i<nums.size() ; i++){
            if(nums[i] == element){
                counter++;
            }
            else{
                counter-- ;
            }

            if(counter == 0){
                element = nums[i+1] ;
            }
        }

        counter=0;

        for(int i=0 ; i<nums.size() ; i++){
            if(element == nums[i]){
                counter++;
            }
        }

        if(counter > (nums.size())/2){
            return element;
        }
        else{
            return -1;
        }
    }
};