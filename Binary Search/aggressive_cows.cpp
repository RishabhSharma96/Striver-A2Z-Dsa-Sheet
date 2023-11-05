// User function Template for C++

class Solution {
public:

    bool canPlace(vector<int> &stalls, int n, int k, int minDist){
    
        int cows=1, currCoord=stalls[0];
        
        for(int i=1 ; i<n; i++){
            if(stalls[i] - currCoord >= minDist){
                cows++;
                currCoord = stalls[i];
            }
        }
        
        return cows>=k ? true : false;
        
    }

    int solve(int n, int k, vector<int> &stalls) {
        
        sort(stalls.begin() , stalls.end());

        int low=0, high = (stalls[n-1] - stalls[0]), ans=-1;
        
        while(low <= high){
            
            int mid = high - (high-low)/2;
            
            if(canPlace(stalls,n,k,mid) == true){
                ans = mid;
                low = mid+1; 
            }
            else{
                high = mid-1;
            }
            
        }
        
        return ans ;
        
    }
};