#include <stdio.h>

int main(){
    int r, c, counter = 0;
    while(scanf("%d %d", &r, &c), r){
        char temp, board[r+2][c+2] = {};
        for(int i = 1; i <= r; ++i){
            getchar();
            for(int j = 1; j <= c; ++j){
                scanf("%c", &temp);
                if(temp == '.'){
                    board[i][j] += '0';
                }else{
                    board[i][j] = '*';
                    if(board[i - 1][j - 1] != '*')
                        ++board[i - 1][j - 1];
                    if(board[i - 1][j] != '*')
                        ++board[i - 1][j];
                    if(board[i - 1][j + 1] != '*')
                        ++board[i - 1][j + 1];
                    if(board[i][j - 1] != '*')
                        ++board[i][j - 1];
                    if(board[i][j + 1] != '*')
                        ++board[i][j + 1];
                    if(board[i + 1][j - 1] != '*')
                        ++board[i + 1][j - 1];
                    if(board[i + 1][j] != '*')
                        ++board[i + 1][j];
                    if(board[i + 1][j + 1] != '*')
                        ++board[i + 1][j + 1];
                }
            }
        }
        if(counter)
            printf("\n");

        printf("Field #%d:\n", ++counter);
        for(int i = 1; i <= r; ++i){
            for(int j = 1; j <= c; ++j){
                printf("%c", board[i][j]);
            }
            printf("\n");
        }
    }
}
