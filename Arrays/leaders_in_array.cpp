class Solution{
    //Function to find the leaders in the array.
    public:
    vector<int> leaders(int a[], int n){
        vector<int> ans;
        int i=n-1 ;
        int prevBigger = -1;
        
        while(i>=0){
            if(a[i] >= prevBigger){
                ans.push_back(a[i]);
                prevBigger = a[i];
            }
            i--;
        }
        
        reverse(ans.begin() , ans.end());
        
        return ans ;
        
    }
};
