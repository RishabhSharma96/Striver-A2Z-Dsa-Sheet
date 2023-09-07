class Solution {
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        
        queue<vector<string>> q ;
        vector<string> usedOnLevel;
        int level = 0 ;
        vector<vector<string>> ans ;
        unordered_set<string> st(wordList.begin() , wordList.end());

        usedOnLevel.push_back(beginWord);
        q.push({beginWord});

        while(!q.empty()){

            vector<string> temp = q.front();
            q.pop();

            if(temp.size() > level){
                level++;
                for(auto it : usedOnLevel){
                    st.erase(it);
                }
            }

            string word = temp.back() ;

            if((word == endWord) && (ans.size() == 0 || ans[0].size() == temp.size())){
                ans.push_back(temp);
            }

            for(int i=0 ; i<word.size() ; i++){
                char currentCharacter = word[i] ;
                for(char ch = 'a' ; ch <= 'z' ; ch++){
                    word[i] = ch ;
                    if(st.find(word) != st.end()){
                        temp.push_back(word);
                        q.push(temp);
                        usedOnLevel.push_back(word);
                        temp.pop_back();
                    }
                }
                word[i] = currentCharacter ;
            }
        }

        return ans;
    }
};