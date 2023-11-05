class Solution{
public:
    int countFactors(int N){
        
        int count = 0;
        
        for(int i=1; i*i<=N ; i++){
            if((N%i) == 0){
                count++;
                if((N/i) != i){
                    count++;
                }
            }
        }
        
        return count ;
        
    }
};