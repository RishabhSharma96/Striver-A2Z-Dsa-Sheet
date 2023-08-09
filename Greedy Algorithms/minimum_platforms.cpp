class Solution{
public:
//Function to find the minimum number of platforms required at the
//railway station such that no train waits.

int findPlatform(int arr[], int dep[], int n)
{
    
    sort(arr,arr+n);
    sort(dep,dep+n);
    
    int arrival=0, departure=0 , platform=0, ans=0 ;
    
    while(arrival < n){
        if(arr[arrival] <= dep[departure]){
            platform++;
            arrival++;
        }
        else{
            platform--;
            departure++;
        }
        ans = max(ans,platform);
    }
    
    return ans;
}
};