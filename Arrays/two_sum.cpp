class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        vector<pair<int,int>> nums_new;

        for(int i=0 ; i<nums.size() ; i++){
            nums_new.push_back({nums[i],i});
        }

        sort(nums_new.begin(),nums_new.end());
        vector<int> ans ;

        int i=0, j=nums.size()-1;

        while(i<j){
            if(nums_new[i].first + nums_new[j].first == target){
                ans.push_back(nums_new[i].second);
                ans.push_back(nums_new[j].second);
                break;
            }
            else if(nums_new[i].first + nums_new[j].first > target){
                j--;
            }
            else{
                i++;
            }
        }

        return ans;
    }
};