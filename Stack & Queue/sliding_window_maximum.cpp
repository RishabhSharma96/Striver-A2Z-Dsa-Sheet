class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        
        deque<int> dq ;
        int i=0, j=0, n=nums.size() ;
        vector<int> ans ;

        while(j<n){

            while((dq.size()>0) && dq.back() < nums[j]){
                dq.pop_back();
            }
            dq.push_back(nums[j]);

            if(j-i+1 < k){
                j++;
            }
            else if (j-i+1 == k){
                ans.push_back(dq.front()) ;
                j++;
            }
            else{
                while(j-i+1 > k){
                    if(nums[i] == dq.front()){
                        dq.pop_front();
                    }
                    i++;
                }
                if (j-i+1 == k){
                    ans.push_back(dq.front()) ;
                }
                j++;
            }
        }
        return ans;
    }
};