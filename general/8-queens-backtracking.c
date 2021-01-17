 
#include <stdio.h>
#define n 8
#define ln printf("\n");

typedef enum {false, true} bool;


void print(int board[n][n]){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            printf(" %c ", board[i][j] == 0 ? '_' : 'Q');
        }  
        ln    
    }
}

void init(int board[n][n]){
    int i, j;
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            board[i][j] = 0;
        }          
    }
}

/*
* We need to check only the left side of the position
  we are in, because we are considering going from the
  left to the right side of the board (thus, the right
  side won't have anything so far).
*/
bool is_safe(int board[n][n], int row, int col){
    int i, j;
    for(i = 0; i < col; i++){
        if(board[row][i] == 1){
            return false;
        }
    }

    for(i = row, j = col; j >= 0 && i >= 0; i--, j--){
        if(board[i][j] == 1){
            return false;
        }
    }

    for(i = row, j = col; i < n && j >= 0; i++, j--){
         if(board[i][j] == 1){
            return false;
        }
    }

    return true;
}

bool n_queens(int board[n][n], int col){
    if (col == n){
        return true;
    }

    int i;
    for(i = 0; i < n; i++){
        if(is_safe(board, i, col)){
            board[i][col] = 1;
            if(n_queens(board, col+1)){
                return true;
            }
            /*
            * if board i,col doesn't lead to the solution
            *  the queen placed in board i,col is removed
            */
            board[i][col] = 0; 
        }        
    }
    return false;
}


int main(){

    int board[n][n];

    init(board);
    print(board);
    ln
    if(n_queens(board, 0)){
        print(board);
    }
    else{
        printf("No solution found");
    }

    return 0;
}
