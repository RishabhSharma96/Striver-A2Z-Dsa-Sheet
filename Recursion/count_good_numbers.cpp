class Solution {
public:

    const int mod = 1e9 + 7;

    long long fast_power(long long a,long long b){

        long long result = 1;

        while(b != 0){
            if(b&1){
                result = (result%mod * a%mod) % mod ;
            }
            a = (a%mod * a%mod) % mod;
            b = b>>1 ;
        }

        return result;
    }

    int countGoodNumbers(long long n) {

        long long evenIndices = n/2 + n%2 ;
        long long oddIndices = n/2 ;

        return (fast_power(5,evenIndices)%mod * fast_power(4,oddIndices)%mod)%mod ;
    }
};