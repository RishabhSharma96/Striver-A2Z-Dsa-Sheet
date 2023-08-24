class Solution {
  public:
    int setBits(int n) {
        int bits=0 ; 
            
        while(n!=0){
            if(n&1){
                bits++;
            }
            n=n>>1;
        }
        
        return bits;
    }
};