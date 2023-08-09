class Solution {
public:

    bool solve(vector<vector<char>>& board, string word, int index, int row, int col){

        if(index == word.size()){
            return true ;
        }

        if (row<0 || row>=board.size() || col<0 || col>=board[0].size() || board[row][col] != word[index]){
            return false;
        } 

        char ch = board[row][col] ;
        board[row][col] = '~' ;

        bool neighbourCalls = solve(board, word, index+1, row-1, col) || solve(board, word, index+1, row+1, col) 
                        || solve(board, word, index+1, row, col-1) || solve(board, word, index+1, row, col+1);

        board[row][col] = ch ;

        return neighbourCalls;

    }

    bool exist(vector<vector<char>>& board, string word) {
        
        int n = board.size() ;
        int m = board[0].size() ;
        queue<pair<int,int>> q ;
        int startAlphabet = word[0] ;

        for(int i=0 ; i<n ; i++){
            for(int j=0 ; j<m ; j++){
                if(board[i][j] == startAlphabet){
                    q.push({i,j});
                }
            }
        }

        while(!q.empty()){
            auto node = q.front() ;
            q.pop() ;

            int row = node.first;
            int col = node.second;

            bool dfsCall = solve(board,word,0,row,col) ;
            if(dfsCall){
                return true ;
            }
        }

        return false;

    }
};