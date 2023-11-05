class Solution{
	public:
	
    vector<int> solve(int n) {
        
        if(n <= 1){
            vector<int> ans ;
            return ans;
        }

        vector<int> sieve(n+1, 1);
        int counter = 0;

        for(int i=2 ; i<=n; i++){
            if(sieve[i] == 1){
                counter++ ;
                for(int j=2 ; i*j <= n ; j++){
                    sieve[i*j] = 0 ;
                }
            }
        }
        
       vector<int> ans;
        for(int i=2 ; i<=n ; i++){
            if(n%i == 0 && sieve[i]){
                ans.push_back(i);
            }
        }

        return ans ;

    }
	
	vector<int> AllPrimeFactors(int N) {
	    return solve(N);
	}
};
