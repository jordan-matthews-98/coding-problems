#include <iostream>
#include <stdio.h>

using namespace std;

int main(){
    int puzzleNum = 0;
    string board[5];
    while(getline(cin, board[0]), board[0] != "Z"){
        for(int i = 1; i < 5; ++i){
            getline(cin, board[i]);
        }
        int r, c;
        for(int i = 0; i < 5; ++i){
            for(int j = 0; j < 5; ++j){
                if(board[i][j] == ' '){
                    r = i;
                    c = j;
                    i = 5;
                    j = 5;
                }
            }
        }
        bool badMove = false;
        char command;
        while(command = getchar(), command != '0'){
            if(command == 'A'){
                if(r == 0){
                    badMove = true;
                }else{
                    board[r][c] = board[--r][c];
                }
            }else if(command == 'B'){
                if(r == 4){
                    badMove = true;
                }else{
                    board[r][c] = board[++r][c];
                }
            }else if(command == 'L'){
                if(c == 0){
                    badMove = true;
                }else{
                    board[r][c] = board[r][--c];
                }
            }else if(command == 'R'){
                if(c == 4){
                    badMove = true;
                }else{
                    board[r][c] = board[r][++c];
                }
            }else if(command != '\n'){
                badMove = true;
            }
        }
        getchar();
        if(puzzleNum)
            printf("\n");

        printf("Puzzle #%d:\n", ++puzzleNum);
        if(badMove){
            printf("This puzzle has no final configuration.\n");
        }else{
            board[r][c] = ' ';
            for(int i = 0; i < 5; ++i){
                for(int j = 0; j < 4; ++j){
                    printf("%c ", board[i][j]);
                }
                printf("%c\n", board[i][4]);
            }
        }
    }
}
