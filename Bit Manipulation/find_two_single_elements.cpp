//User function Template for C++
class Solution{
    public:
    vector<long long int> twoOddNum(long long int Arr[], long long int N)  
    {
        long long xorr = 0 ;
        for(int i=0; i<N; i++){
            xorr ^= Arr[i];
        }
        
        long long cnt=0;
        while(xorr){
            if(xorr & (1<<cnt)){
                break ;
            }
            cnt++;
        }
        
        long long oneClub=0, zeroClub=0 ;
        for(int i=0; i<N; i++){
            if(Arr[i] & (1<<cnt)){
                oneClub ^= Arr[i] ;
            }
            if(!(Arr[i] & (1<<cnt))){
                zeroClub ^= Arr[i] ;
            }
        }
        
        if(zeroClub>oneClub){
            return {zeroClub, oneClub} ;
        }
        else{
            return {oneClub, zeroClub};
        }
    }
};