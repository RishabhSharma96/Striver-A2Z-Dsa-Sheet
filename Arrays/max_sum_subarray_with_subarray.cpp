class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        long long sum = 0 ;
        long long maxi = INT_MIN ;

        int start=0, ansStart=0, ansEnd = 0;

        for(int i=0 ; i <nums.size() ; i++){

            if(sum == 0){
                start = i ;
            }

            sum += nums[i] ;
            
            if(sum > maxi){
                maxi = sum ;
                ansStart = start ;
                ansEnd = i ;
            }

            if(sum < 0){
                sum = 0; 
            }
        }

        for(int i=ansStart ; i<=ansEnd; i++){
            cout<< nums[i] <<" ";
        }

        return maxi ;
    }
};