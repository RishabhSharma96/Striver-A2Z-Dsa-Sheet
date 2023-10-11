class Solution{
public:
    int subsetXOR(vector<int> arr, int n, int k) {
        
        int xr = 0;
        map<int, int> mpp; // for{cummulative_xor, number_of_time_it_appears}
        mpp[xr]++; 
        int cnt = 0;
    
        for (int i = 0; i < n; i++) {
            xr = xr ^ arr[i];
            int x = xr ^ k;
            cnt += mpp[x];
            mpp[xr]++;
        }
        return cnt;
    }
};
