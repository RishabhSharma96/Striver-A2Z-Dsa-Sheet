class Solution {
public:
    string frequencySort(string s) {
        map<char,int> freq;
        priority_queue<pair<int,char>> pq;

        for(char c: s){
            freq[c]++;
        }

        for(auto it:freq){
            pq.push({it.second,it.first});
        }

        s = "";

        while(!pq.empty()){
            auto node = pq.top() ;
            char ch = node.second;
            int times = node.first;
            pq.pop();

            while(times--){
                s += ch;
            }
        }

        return s;
    }
};