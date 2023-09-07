class Solution {
public:

    int getMax(vector<int> & arr){
        int ans = INT_MIN ;
        for(int i=0 ; i<arr.size(); i++){
            ans = max(ans,arr[i]);
        }
        return ans;
    }

    int getSum(vector<int> & arr){
        int ans = 0 ;
        for(int i=0 ; i<arr.size(); i++){
            ans += arr[i];
        }
        return ans;
    }

    bool helper(vector<int> & weights, int capacity, int maxDays){

        int days = 1; 
        int load = 0;
        int n = weights.size(); 
        for (int i = 0; i < n; i++) {
            if (load + weights[i] > capacity) {
                days += 1; 
                load = weights[i]; 
            }
            else {
                load += weights[i];
            }
        }
        return (days<=maxDays);
    }

    int shipWithinDays(vector<int>& weights, int days) {
        
        int low = getMax(weights), high = getSum(weights) ;
        int ans = 0;

        while(low <= high){
            int mid = low + (high-low)/2 ;

            if(helper(weights,mid,days)){
                high = mid-1 ;
                ans = mid;
            }
            else{
                low = mid+1;
            }
        }

        return ans;

    }
};