class Solution {
public:

    int getMin(vector<int>& bloomDay){
        int ans = INT_MAX ;
        for(int i=0 ; i<bloomDay.size() ; i++){
            ans = min(ans,bloomDay[i]);
        }
        return ans;
    }

    int getMax(vector<int>& bloomDay){
        int ans = INT_MIN ;
        for(int i=0 ; i<bloomDay.size() ; i++){
            ans = max(ans,bloomDay[i]);
        }
        return ans;
    }

    bool helper(vector<int>& bloomDay, int m, int k, int day){
        int cnt=0 ;
        int flowerGroup=0 ;

        for(int i=0 ; i<bloomDay.size() ; i++){
            if(bloomDay[i] <= day){
                cnt++;
            }
            else{
                flowerGroup += (cnt/k) ;
                cnt=0 ;
            }
        }
        
        flowerGroup += (cnt/k) ;
        return flowerGroup >= m ;
    }

    int minDays(vector<int>& bloomDay, int m, int k) {

        if((long long)m*k > bloomDay.size()){
            return -1;
        } 
        
        int low = getMin(bloomDay);
        int high = getMax(bloomDay);

        while(low <= high){
            int mid = low + (high-low)/2;

            if(helper(bloomDay,m,k,mid) == true){
                high = mid-1;
            }
            else{
                low = mid+1;
            }
        }

        return low ;

    }
};