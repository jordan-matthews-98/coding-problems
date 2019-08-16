#include<stdio.h>

char board[10][10];

bool diagonalCheck(int row, int col, char king){
    int r = row, c = col;
    while(board[++r][--c] == '.');
    if(board[r][c] == king)
        return true;

    r = row;
    c = col;
    while(board[++r][++c] == '.');
    if(board[r][c] == king)
        return true;

    r = row;
    c = col;
    while(board[--r][--c] == '.');
    if(board[r][c] == king)
        return true;

    r = row;
    c = col;
    while(board[--r][++c] == '.');
    if(board[r][c] == king)
        return true;

    return false;
}

bool orthogonalCheck(int row, int col, char king){
    int r = row, c = col;
    while(board[++r][c] == '.');
    if(board[r][c] == king)
        return true;

    r = row;
    while(board[--r][c] == '.');
    if(board[r][c] == king)
        return true;

    r = row;
    while(board[r][--c] == '.');
    if(board[r][c] == king)
        return true;

    c = col;
    while(board[r][++c] == '.');
    if(board[r][c] == king)
        return true;

    return false;
}

int main(){
    int counter = 0;
    bool allDots = false;

    for(int i = 0; i < 10; i++){
        board[i][0] = 'n';
        board[i][9] = 'n';
        board[0][i] = 'n';
        board[9][i] = 'n';
    }

    while(!allDots){
        bool winner = false;
        allDots = true;

        for(int i = 1; i < 9; i++){
            for(int j = 1; j < 9; j++){
                scanf("%c", &board[i][j]);
                if(board[i][j] == 'k'){
                    allDots = false;
                }
            }
            getchar();
        }
        if(!allDots){
            getchar();
            int r, c;
            for(int i = 1; i < 9; i++){
                for(int j = 1; j < 9; j++){
                    switch(board[i][j]){
                        case 'P':
                            if(board[i-1][j+1] == 'k' || board[i-1][j-1] == 'k'){
                                i = j = 9;
                                printf("Game #%d: black king is in check.\n", ++counter);
                                winner = true;
                            }
                            break;
                        case 'p':
                            if(board[i+1][j+1] == 'K' || board[i+1][j-1] == 'K'){
                                i = j = 9;
                                printf("Game #%d: white king is in check.\n", ++counter);
                                winner = true;
                            }
                            break;
                        case 'R':
                            if(orthogonalCheck(i, j, 'k')){
                                i = j = 9;
                                printf("Game #%d: black king is in check.\n", ++counter);
                                winner = true;
                            }
                            break;
                        case 'r':
                            if(orthogonalCheck(i, j, 'K')){
                                i = j = 9;
                                printf("Game #%d: white king is in check.\n", ++counter);
                                winner = true;
                            }
                            break;
                        case 'B':
                            if(diagonalCheck(i, j, 'k')){
                                i = j = 9;
                                printf("Game #%d: black king is in check.\n", ++counter);
                                winner = true;
                            }
                            break;
                        case 'b':
                            if(diagonalCheck(i, j, 'K')){
                                i = j = 9;
                                printf("Game #%d: white king is in check.\n", ++counter);
                                winner = true;
                            }
                            break;
                        case 'Q':
                            if(diagonalCheck(i, j, 'k') || orthogonalCheck(i, j, 'k')){
                                i = j = 9;
                                printf("Game #%d: black king is in check.\n", ++counter);
                                winner = true;
                            }
                            break;
                        case 'q':
                            if(diagonalCheck(i, j, 'K') || orthogonalCheck(i, j, 'K')){
                                i = j = 9;
                                printf("Game #%d: white king is in check.\n", ++counter);
                                winner = true;
                            }
                            break;
                        case 'N':
                            if(board[i-2][j+1] == 'k' ||
                               board[i-1][j+2] == 'k' ||
                               board[i-2][j-1] == 'k' ||
                               board[i-1][j-2] == 'k' ||
                               board[i+2][j-1] == 'k' ||
                               board[i+2][j+1] == 'k' ||
                               board[i+1][j+2] == 'k' ||
                               board[i+1][j-2] == 'k'){
                                i = j = 9;
                                printf("Game #%d: black king is in check.\n", ++counter);
                                winner = true;
                            }
                            break;
                        case 'n':
                            if(board[i-2][j+1] == 'K' ||
                               board[i-1][j+2] == 'K' ||
                               board[i-2][j-1] == 'K' ||
                               board[i-1][j-2] == 'K' ||
                               board[i+2][j-1] == 'K' ||
                               board[i+2][j+1] == 'K' ||
                               board[i+1][j+2] == 'K' ||
                               board[i+1][j-2] == 'K'){
                                i = j = 9;
                                printf("Game #%d: white king is in check.\n", ++counter);
                                winner = true;
                            }
                            break;
                        default: break;
                    }
                }
            }
            if(!winner){
                printf("Game #%d: no king is in check.\n", ++counter);
            }
        }
    }
}
