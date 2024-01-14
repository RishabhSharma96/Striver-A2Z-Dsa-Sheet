class Solution {
public:

    const int mod = 1e9+7 ;

    void nextSmallerToRight(vector<int> arr, vector<int> & nsr){

        int n = arr.size() ;
        stack<pair<int,int>> s ;
        s.push({-1,-1});

        for(int i=n-1; i>=0 ; i--){
            while(!s.empty() && s.top().first >= arr[i]){
                s.pop();
            }
            nsr.push_back(s.top().second);
            s.push({arr[i], i});
        }

        reverse(nsr.begin(), nsr.end());
    }

    void nextSmallerToLeft(vector<int> arr, vector<int> & nsl){

        int n = arr.size() ;
        stack<pair<int,int>> s ;
        s.push({-1,-1});

        for(int i=0; i<n ; i++){
            while(!s.empty() && s.top().first > arr[i]){
                s.pop();
            }
            nsl.push_back(s.top().second);
            s.push({arr[i], i});
        }
    }

    int sumSubarrayMins(vector<int>& arr) {
        int n=arr.size() ;
        vector<int> nsr ;
        nextSmallerToRight(arr,nsr);
        vector<int> nsl ;
        nextSmallerToLeft(arr,nsl);

        for(int i=0 ; i<n ; i++){
            if(nsr[i] == -1){
                nsr[i] = n;
            }
        }

        long long sum = 0;

        for(int i=0 ; i<n ; i++){
            long left = i - nsl[i]; 
            long right = nsr[i] - i; 
            sum = (sum + left * right * arr[i]) % mod;
        }

        for(auto i=0 ; i<n ; i++){
            cout<<nsl[i] <<" "<< nsr[i];
            cout<<endl;
        }

        return sum;
    }
};