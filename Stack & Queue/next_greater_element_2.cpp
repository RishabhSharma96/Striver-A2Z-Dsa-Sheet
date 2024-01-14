class Solution {
public:
    vector<int> nextGreaterElements(vector<int>& nums) {

        stack<int> s ;
        s.push(-1);
        int n = nums.size() ;
        vector<int> ans ;

        for(int i=n-1; i>=0 ;i--){
            while(!s.empty() && s.top()<=nums[i]){
                s.pop();
            }
            s.push(nums[i]);
        }

        for(int i=n-1; i>=0 ;i--){
            while(!s.empty() && s.top()<=nums[i]){
                s.pop();
            }
            ans.push_back(s.empty() ? -1 : s.top());
            s.push(nums[i]);
        }

        reverse(ans.begin() , ans.end());
        return ans ;

    }
};