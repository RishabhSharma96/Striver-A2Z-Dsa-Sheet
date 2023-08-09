class Solution
{
public:

    void solve(vector<int>& ans,int sum, int index, int size, vector<int>& arr){
        if(index == size){
            ans.push_back(sum);
            return ;
        }
        
        solve(ans,sum+arr[index],index+1,size,arr);
        solve(ans,sum,index+1,size,arr);
    }

    vector<int> subsetSums(vector<int> arr, int N)
    {
        vector<int> ans ;
        solve(ans,0,0,N,arr);
        return ans;
    }
};