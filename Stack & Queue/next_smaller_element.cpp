//User function Template for C++

class Solution{
    
    public:
    vector<int> help_classmate(vector<int> arr, int n) 
    { 
        stack<int> st;
        st.push(-1);
        
        vector<int> ans ;
        
        for(int i=n-1; i>=0 ; i--){
            int element = arr[i] ;
            
            while(st.top() >= element){
                st.pop() ;
            }
            
            ans.push_back(st.top());
            st.push(element);
        }
        
        reverse(ans.begin() , ans.end());
        return ans ;
    } 
};