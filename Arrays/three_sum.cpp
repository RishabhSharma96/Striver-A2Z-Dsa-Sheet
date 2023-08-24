class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin() , nums.end()) ;
        vector<vector<int>> ans ;

        for(int i=0 ; i<nums.size(); i++){
            if(i>0 && nums[i] == nums[i-1]){
                continue ;
            }

            int element = nums[i] ;
            int j=i+1 , k=nums.size()-1;

            while(j<k){
                if(nums[j] + nums[k] + element == 0){
                    ans.push_back({{element,nums[j],nums[k]}});
                   j++;
                   k--;
                    while(j<k && nums[j] == nums[j-1]){
                        j++;
                    }
                    while(j<k && nums[k] == nums[k+1]){
                        k--;
                    }
                }
                else if(nums[j] + nums[k] + element > 0){
                    k--;
                }
                else{
                    j++;
                }
            }
        }

        return ans;
    }
};