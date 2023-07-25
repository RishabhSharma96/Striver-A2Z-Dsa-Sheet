class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        
        unordered_map<int,int> nges ;
        stack<int> s ;
        s.push(-1);

        for(int i=nums2.size()-1 ; i>=0 ; i--){
            
            while(s.top()<nums2[i]){
                if(s.top()==-1){
                    break;
                }
                s.pop();
            }
            nges[nums2[i]] = s.top();
            s.push(nums2[i]);
        }

        vector<int> ans ;
        for(int i=0 ; i<nums1.size() ; i++){
            ans.push_back(nges[nums1[i]]);
        }

        return ans ;
    }
};