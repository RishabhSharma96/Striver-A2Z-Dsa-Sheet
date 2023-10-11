class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        
        unordered_set<string> st ;
        queue<pair<string,int>> q ;
        
        for(auto it : wordList){
            st.insert(it);
        }
        
        q.push({beginWord, 1});
        st.erase(beginWord);

        while(!q.empty()){

            string word = q.front().first;
            int steps = q.front().second ;
            q.pop();

            if(word == endWord){
                return steps ;
            }

            for(int i=0 ; i<word.size() ; i++){
                char originalCharacter = word[i] ;
                for(char ch = 'a' ; ch <= 'z' ; ch++){
                    word[i] = ch ;
                    if(st.find(word) != st.end()){
                        q.push({word,steps+1});
                        st.erase(word);
                    }
                }
                word[i] = originalCharacter;
            }
        }

        return 0 ;
    }
};