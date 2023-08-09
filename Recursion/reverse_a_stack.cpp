//User function Template for C++

class Solution{
public:

    void solve2(stack<int> & st, int element){
        if(st.empty()){
            st.push(element);
            return ;
        }
        
        int num = st.top() ;
        st.pop() ;
        solve2(st,element);
        st.push(num);
    }

    void solve(stack<int> & st){
        
        if(st.empty()){
            return ;
        }
        
        int num = st.top();
        st.pop() ;
        solve(st);
        solve2(st,num);
    }

    void Reverse(stack<int> &St){
        solve(St);
    }
};