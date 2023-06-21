class Solution {
public:
    bool rotateString(string s, string goal) {

        if(s.size() != goal.size()) return false;

        vector<int> occurences;

        for(int i=0 ; i<s.size(); i++){
            if(s[i] == goal[0]){
                occurences.push_back(i);
            }
        }

        if(occurences.size() == 0){
            return false;
        }

        int j=0;
        for(int i=0 ; i<goal.size(); i++){
            if(goal[i] == s[(occurences[j]+i)%(goal.size())]){
                continue;
            }
            else{
                j++;
                if(j == occurences.size()){
                    return false;
                }
                i=0;
            }
        }

        return true;
    }
};