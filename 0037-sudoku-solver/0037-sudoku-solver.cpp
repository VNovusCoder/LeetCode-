class Solution {
public: 

    bool is_safe(vector<vector<char>> &board , int row , int col , char dig){
        // horizontally
        for(int j=0 ; j<9 ; j++){
            if( board[row][j] == dig ){
                return false;
            }
        }
        /// vertically
        for(int j=0 ; j<9 ; j++){
            if( board[j][col] == dig ){
                return false;
            }
        }

        // 3*3 grid
        for(int i= (row/3)*3 ; i<= (row/3)*3 + 2 ; i++){
            for( int j= (col/3)*3 ; j<= (col/3)*3 + 2 ; j++){
                if(board[i][j] == dig){
                    return false;
                }
            }
        }

        return true;
    }


    bool solver(vector<vector<char>> &board , int row , int col){

        if ( row == 9){
            return true;
        }

        int nextRow = row , nextCol = col + 1;
        if(nextCol ==9){
            nextRow = row +1;
            nextCol = 0;
        }

        if(board[row][col] != '.'){    
            return solver(board , nextRow , nextCol);
        }

        for(char i='1' ; i<='9' ; i++){
            if(is_safe(board , row ,col , i)){
                board[row][col] = i;
                if(solver(board,nextRow , nextCol )){
                    return true;
                }
                // backtracking
                board[row][col] = '.';
            }
        }

        return false;
    }


    void solveSudoku(vector<vector<char>>& board) {

        solver(board , 0 , 0);
    }
};