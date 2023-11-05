class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        
        unordered_map<char,int> mp ;
        for(auto it:tasks){
            mp[it]++;
        }

        priority_queue<int> pq ;
        for(auto it : mp){
            pq.push(it.second);
        }

        int totalTime = 0;

        while(!pq.empty()){
            vector<int> temp ;
            int time=0 ;
            for(int i=0 ; i<=n ; i++){
                if(!pq.empty()){
                    time++;
                    if(pq.top() - 1 != 0){
                        temp.push_back(pq.top() - 1);
                    }
                    pq.pop();
                }
            }

            for(auto it : temp){
                pq.push(it);
            }

            totalTime += pq.empty() ? time : n+1 ;
        }

        return totalTime;
    }
};