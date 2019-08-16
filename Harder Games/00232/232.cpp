#include <stdio.h>

int main(){
    freopen("out.txt", "w", stdout);
    int r, c, puzNum = 0;
    while(scanf("%d%d", &r, &c) == 2, r){
        bool downWordStart[r + 1][c + 1] = {}, acrossWordStart[r + 1][c + 1] = {};
        char board[r][c];
        for(int i = 0; i < r; ++i){
            acrossWordStart[i][0] = true;
        }
        for(int i = 0; i < c; ++i){
            downWordStart[0][i] = true;
        }
        for(int i = 0; i < r; ++i){
            getchar();
            for(int j = 0; j < c; ++j){
                scanf("%c", &board[i][j]);
                if(board[i][j] == '*'){
                    acrossWordStart[i][j] = false;
                    downWordStart[i][j] = false;
                    acrossWordStart[i][j + 1] = true;
                    downWordStart[i + 1][j] = true;
                }
            }
        }
        int wordStartNums[r][c], wordNum = 0;
        for(int i = 0; i < r; ++i){
            for(int j = 0; j < c; ++j){
                if(acrossWordStart[i][j] || downWordStart[i][j]){
                    wordStartNums[i][j] = ++wordNum;
                }
            }
        }
        if(puzNum)
            printf("\n");
        printf("puzzle #%d:\nAcross\n", ++puzNum);
        for(int i = 0; i < r; ++i){
            for(int j = 0; j < c; ++j){
                if(acrossWordStart[i][j]){
                    printf("%3d.", wordStartNums[i][j]);
                    int row = i, col = j;
                    while(col < c && board[row][col] != '*'){
                        printf("%c", board[row][col++]);
                    }
                    printf("\n");
                }
            }
        }
        printf("Down\n");
        for(int i = 0; i < r; ++i){
            for(int j = 0; j < c; ++j){
                if(downWordStart[i][j]){
                    printf("%3d.", wordStartNums[i][j]);
                    int row = i, col = j;
                    while(row < r && board[row][col] != '*'){
                        printf("%c", board[row++][col]);
                    }
                    printf("\n");
                }
            }
        }
    }
}
