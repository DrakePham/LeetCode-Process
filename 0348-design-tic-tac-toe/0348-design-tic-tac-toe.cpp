class TicTacToe {
public:
    vector<vector<int>> myBoard;
    TicTacToe(int n) {
        vector<vector<int>> board(n, vector<int>(n, 0));
        myBoard = board;
    }
    
    bool isVerticalWin(int col, int player){
        for(int i = 0; i < myBoard.size(); i++){
            if(player != myBoard[i][col]) return false;
        }
        return true;
    }

    bool isHorizontalWin(int row, int player){
        for(int i = 0; i < myBoard.size(); i++){
            if(player != myBoard[row][i]) return false;
        }
        return true;
    }

    bool isDiagonalWin(int player){
        bool a = true;
        bool b = true;
        int size = myBoard.size();
        for(int i = 0; i < size; i++){
            if(player != myBoard[i][i]) a = false;
            if(player != myBoard[i][size - 1 - i]) b = false;
        }
        return a || b;
    }

    int move(int row, int col, int player) {
        myBoard[row][col] = player;
        if(isVerticalWin(col, player) || isHorizontalWin(row, player) || isDiagonalWin(player)) return player;
        return 0;
    }
};

/**
 * Your TicTacToe object will be instantiated and called as such:
 * TicTacToe* obj = new TicTacToe(n);
 * int param_1 = obj->move(row,col,player);
 */


 /*
board

isVerticalWin
isHorizontalWin
isDiagonalWin


in move function, 


 */