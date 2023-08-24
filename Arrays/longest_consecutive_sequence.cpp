class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        
        int n = nums.size() ;

        if(n == 0){
            return 0 ;
        }

        int longestSequence = 1 ;
        unordered_set<int> st;

        for(auto it : nums){
            st.insert(it);
        }

        for(auto it : st){
            if(st.find(it-1) == st.end()){
                int number = it;
                int count = 1;
                while(st.find(number+1) != st.end()){
                    number++;
                    count++;
                }
                longestSequence = max(longestSequence,count);
            }
        }

        return longestSequence;
    }
};