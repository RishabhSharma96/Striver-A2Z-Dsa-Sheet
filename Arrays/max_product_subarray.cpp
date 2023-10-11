class Solution {
public:
    int maxProduct(vector<int>& nums) {
        
        int productPrefix=1, productSuffix=1, n=nums.size(), ans=INT_MIN;

        for(int i=0 ; i<n ; i++){
            if(productSuffix == 0){
                productSuffix=1;
            }
            if(productPrefix == 0){
                productPrefix=1;
            }

            productPrefix = productPrefix * nums[i] ;
            productSuffix = productSuffix * nums[n-i-1] ;

            ans = max(ans, max(productSuffix,productPrefix));
        }
        return ans;
    }
};