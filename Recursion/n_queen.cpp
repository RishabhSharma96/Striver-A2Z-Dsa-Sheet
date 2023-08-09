class Solution {
public:

    bool isQueenSafe(vector<string>& chessboard,int row,int col,int n){

        int i=0 ;

        while(i<n){
            if(chessboard[row][i] == 'Q'){
                return false ;
            }
            i++ ;
        }

        i=0;

        while(i<n){
            if(chessboard[i][col] == 'Q'){
                return false ;
            }
            i++ ;
        }

        i=row ;
        int j=col ;

        while(i>=0 && j>=0){
            if(chessboard[i][j] == 'Q'){
                return false ;
            }
            i-- ;
            j-- ;
        }

        i=row;
        j=col ;

        while(i>=0 && j<n){
            if(chessboard[i][j] == 'Q'){
                return false ;
            }
            i-- ;
            j++ ;
        }
        
        return true ;
    }

    void solve(vector<vector<string>> & ans , vector<string> & board, int row, int n){

        if(row == n){
            ans.push_back(board);
            return ;
        }

        for(int i=0 ; i<n ; i++){
            if(isQueenSafe(board,row,i,n)){
                board[row][i] = 'Q';
                solve(ans,board,row+1,n);
                board[row][i] = '.';
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans ;
        vector<string> board ;
        string temp ;

        for(int i=0 ; i<n ; i++){
            temp.push_back('.');
        }

        for(int i=0 ; i<n ; i++){
            board.push_back(temp);
        }

        solve(ans,board,0,n);
        return ans;
    }
};