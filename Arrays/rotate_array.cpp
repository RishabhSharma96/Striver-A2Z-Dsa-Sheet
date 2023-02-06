class Solution {
public:

    void rotate(vector<int>& nums, int k) {
        int n = nums.size() ;

        k %= n;
        
        int a = 0 ;
        int b = n-1 ;

        while(a<=b){
            swap(nums[a++] , nums[b--]);
        }

        a = 0 ;
        b = k-1 ;

        while(a<=b){
            swap(nums[a++] , nums[b--]);
        }

        a = k ;
        b = n-1 ;

        while(a<=b){
            swap(nums[a++] , nums[b--]);
        }
    }
};