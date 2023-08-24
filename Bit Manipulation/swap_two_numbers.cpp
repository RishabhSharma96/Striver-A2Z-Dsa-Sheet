//User function Template for C++

class Solution{   
public:
    pair<int, int> get(int a, int b){
        b=a^b;
        a=a^b;
        b=a^b;
        return {a,b};
    }
};