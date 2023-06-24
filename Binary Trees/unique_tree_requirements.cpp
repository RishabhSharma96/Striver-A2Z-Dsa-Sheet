//User function Template for C++

class Solution
{
public:
    bool isPossible(int a,int b)
    {
        if((a==2 && b!=2 && b>0) || (b==2 && a!=2 && a>0)){ 
            return true;
            
        }
        
        else{
            return false;
        }
    }
};