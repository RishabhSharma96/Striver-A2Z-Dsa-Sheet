//User function template for C++

class Solution
{
  public:
  
    long long painterCount(int arr[],int n,int k,int paint){
        long long painter=1;
        long long painted=0;
        for(int i=0;i<n;i++){
            if((long long)arr[i]+painted<=paint){
                painted+=(long long)arr[i];
            }
            else{
                painter++;
                painted=arr[i];
            }
        }
        return painter;
    }
    long long minTime(int arr[], int n, int k)
    {
        long long maxi=INT_MIN;
        long long sum=0;
        for(int i=0;i<n;i++){
            maxi=max(maxi,(long long)arr[i]);
        }
        
        for(int i=0;i<n;i++){
            sum+=arr[i];
        }
        
        long long l=maxi;
        long long h=sum;
        while(l<=h){
            int mid=l+((h-l)/2);
            long long count=painterCount(arr,n,k,mid);
            if(count>k){
                l=mid+1;
            }
            else{
                h=mid-1;
            }
        }
        
        return l;
    }
};