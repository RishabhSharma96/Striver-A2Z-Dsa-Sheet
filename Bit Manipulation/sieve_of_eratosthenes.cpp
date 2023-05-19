class Solution {
public:
    int countPrimes(int n) {
        
        if(n <= 1){
            return 0 ;
        }

        vector<int> sieve(n+1, 1);
        int counter = 0;

        for(int i=2 ; i<n; i++){
            if(sieve[i] == 1){
                counter++ ;
                for(int j=2 ; i*j < n ; j++){
                    sieve[i*j] = 0 ;
                }
            }
        }

        return counter ;

    }
};