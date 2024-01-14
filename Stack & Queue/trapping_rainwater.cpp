class Solution {
public:
    int trap(vector<int>& height) {
        
        int n = height.size() ;
        vector<int> maxl(n,INT_MIN);
        vector<int> maxr(n,INT_MIN);

        int leftMax = height[0], rightMax = height[n-1] ;

        for(int i=0 ; i<n ; i++){
            maxl[i] = max(leftMax, height[i]);
            leftMax = max(leftMax,height[i]);
        }

        for(int i=n-1 ; i>=0 ; i--){
            maxr[i] = max(rightMax, height[i]);
            rightMax = max(rightMax,height[i]);
        }

        int totalWater = 0;
        for(int i=0 ; i<n ; i++){
            totalWater += min(maxl[i], maxr[i]) - height[i] ;
        }

        return totalWater ;

    }
};