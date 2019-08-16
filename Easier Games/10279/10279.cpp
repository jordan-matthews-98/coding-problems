#include <stdio.h>

int main(){
    int n, t;
    scanf("%d", &t);
    for(int testCase = 0; testCase < t; ++testCase){
        scanf("%d", &n);
        char temp, board[n+2][n+2] = {};
        for(int i = 1; i <= n; ++i){
            getchar();
            for(int j = 1; j <= n; ++j){
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
        bool lost = false;
        char bombs[n+1][n+1];
        for(int i = 1; i <= n; ++i){
            getchar();
            for(int j = 1; j <= n; ++j){
                scanf("%c", &temp);
                bombs[i][j] = board[i][j];
                if(temp == '.'){
                    board[i][j] = '.';
                }else{
                    if(board[i][j] == '*'){
                        lost = true;
                    }
                }
            }
        }
        if(lost){
            for(int i = 1; i <= n; ++i){
                for(int j = 1; j <= n; ++j){
                    if(bombs[i][j] == '*'){
                        board[i][j] = '*';
                    }
                }
            }
        }
        if(testCase)
            printf("\n");

        for(int i = 1; i <= n; ++i){
            for(int j = 1; j <= n; ++j){
                printf("%c", board[i][j]);
            }
            printf("\n");
        }
    }
}
