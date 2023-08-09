//User function Template for C++

class Solution{
public:

    void solve(int index, int num, string temp){
        if(index == num){
            cout<<temp<<" ";
            return ;
        }
        
        if(temp.back() == '1'){
            solve(index+1,num,temp+"0");
        }
        else{
            solve(index+1,num,temp+"0");
            solve(index+1,num,temp+"1");
        }
    }

    void generateBinaryStrings(int num){
        solve(0,num,"");
    }
};