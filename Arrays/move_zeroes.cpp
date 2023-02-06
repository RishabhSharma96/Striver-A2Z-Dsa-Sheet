class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        
        int n = nums.size() ;

        int z = 0;

        for(int i=0 ; i<n; i++){
            if(nums[i] == 0){
                z=i;
                break;
            }
        }

        int nz = z+1 ;

        while(z<n && nz<n){
            if(nums[nz] != 0 && nums[z] == 0){
                swap(nums[z++],nums[nz++]);
            }
            else{
                nz++ ;
            }
        }
    }
};