class Solution {
public:

    double fast_power(double a,long long b){

        double result = 1.0;

        while(b != 0){
            if(b&1){
                result = (result * a) ;
            }
            a = (a * a) ;
            b = b>>1 ;
        }

        return result;
    }

    double myPow(double x, int n) {
        if(n<0){
            return 1/fast_power(x,abs(n));
        }
        else{
            return fast_power(x,n);
        }
    }
};