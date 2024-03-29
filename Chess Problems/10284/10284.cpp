#include <stdio.h>
#include <string.h>
#include <iostream>

using namespace std;

char board[10][10];
bool unsafe[10][10];

void diagonalSet(int row, int col){
    int r = row, c = col;
    while(board[++r][--c] == ' ')
        unsafe[r][c] = true;
    r = row;
    c = col;
    while(board[++r][++c] == ' ')
        unsafe[r][c] = true;
    r = row;
    c = col;
    while(board[--r][--c] == ' ')
        unsafe[r][c] = true;
    r = row;
    c = col;
    while(board[--r][++c] == ' ')
        unsafe[r][c] = true;
}

void orthogonalSet(int row, int col){
    int r = row, c = col;
    while(board[++r][c] == ' ')
        unsafe[r][c] = true;
    r = row;
    while(board[--r][c] == ' ')
        unsafe[r][c] = true;
    r = row;
    while(board[r][--c] == ' ')
        unsafe[r][c] = true;
    c = col;
    while(board[r][++c] == ' ')
        unsafe[r][c] = true;
}

int main(){
    string fen;
    while(getline(cin, fen)){
        memset(board, ' ', 100);
        for(int i = 0; i < 10; i++){
            board[i][0] = '\0';
            board[i][9] = '\0';
            board[0][i] = '\0';
            board[9][i] = '\0';
        }
        memset(unsafe, false, sizeof(unsafe));
        int counter = 0;
        for(int i = 1; i < 9; ++i, ++counter){
            for(int j = 1; j < 9; ++counter){
                if(fen[counter] > '0' && fen[counter] < '9')
                    j += fen[counter] - '0';
                else{
                    board[i][j] = fen[counter];
                    unsafe[i][j] = true;
                    ++j;
                }
            }
        }
        int r, c;
        for(int i = 1; i < 9; ++i){
            for(int j = 1; j < 9; ++j){
                switch(board[i][j]){
                    case 'P':
                        unsafe[i-1][j+1] = true;
                        unsafe[i-1][j-1] = true;
                        break;
                    case 'p':
                        unsafe[i+1][j+1] = true;
                        unsafe[i+1][j-1] = true;
                        break;
                    case 'R':
                    case 'r':
                        orthogonalSet(i, j);
                        break;
                    case 'B':
                    case 'b':
                        diagonalSet(i, j);
                        break;
                    case 'Q':
                    case 'q':
                        orthogonalSet(i, j);
                        diagonalSet(i, j);
                        break;
                    case 'N':
                    case 'n':
                        unsafe[i-2][j+1] = true;
                        unsafe[i-1][j+2] = true;
                        unsafe[i-2][j-1] = true;
                        unsafe[i-1][j-2] = true;
                        unsafe[i+2][j-1] = true;
                        unsafe[i+2][j+1] = true;
                        unsafe[i+1][j+2] = true;
                        unsafe[i+1][j-2] = true;
                        break;
                    case 'K':
                    case 'k':
                        for(int k = i - 1; k < i + 2; ++k){
                            for(int l = j - 1; l < j + 2; ++l){
                                unsafe[k][l] = true;
                            }
                        }
                        break;
                    default: break;
                }
            }
        }
        counter = 0;
        for(int i = 1; i < 9; ++i){
            for(int j = 1; j < 9; ++j){
                if(!unsafe[i][j])
                    ++counter;
            }
        }
        printf("%d\n", counter);
    }
}
