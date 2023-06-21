class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int> pq;

        for(auto it:nums){
            pq.push(it);
        }

        int counter=k-1 ;
        while(counter--){
            pq.pop();
        }

        return pq.top() ;

    }
};