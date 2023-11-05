// O(N) Solution
class Solution {
public:
    bool isPowerOfTwo(int n) {

        if(n == 0){
            return 0;
        }  

        while(n % 2 == 0){
            n /= 2;
        } 
        
        return n == 1;
    }
};

// O(1) Solution
class Solution {
public:
    bool isPowerOfTwo(int n) {
        return (n&(n-1))==1 ? false : true;
    }
};