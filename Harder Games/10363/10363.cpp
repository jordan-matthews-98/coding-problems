#include <stdio.h>

int main(){
    int games;
    scanf("%d", &games);

    for(int game = 0; game < games; ++game){
        if(game)
            getchar();
        char grid[3][3];
        int xs = 0, os = 0;
        for(int i = 0; i < 3; ++i){
            getchar();
            for(int j = 0; j < 3; ++j){
                scanf("%c", &grid[i][j]);
                if(grid[i][j] == 'X'){
                    ++xs;
                }else if(grid[i][j] == 'O'){
                    ++os;
                }
            }
        }
        bool xWin = false, oWin = false;
        if(grid[0][0] == grid[0][1] && grid[0][1] == grid[0][2]){
            if(grid[0][0] == 'X'){
                xWin = true;
            }else if(grid[0][0] == 'O'){
                oWin = true;
            }
        }
        if(grid[1][0] == grid[1][1] && grid[1][1] == grid[1][2]){
            if(grid[1][0] == 'X'){
                xWin = true;
            }else if(grid[1][0] == 'O'){
                oWin = true;
            }
        }
        if(grid[2][0] == grid[2][1] && grid[2][1] == grid[2][2]){
            if(grid[2][0] == 'X'){
                xWin = true;
            }else if(grid[2][0] == 'O'){
                oWin = true;
            }
        }
        if(grid[0][0] == grid[1][0] && grid[1][0] == grid[2][0]){
            if(grid[0][0] == 'X'){
                xWin = true;
            }else if(grid[0][0] == 'O'){
                oWin = true;
            }
        }
        if(grid[0][1] == grid[1][1] && grid[1][1] == grid[2][1]){
            if(grid[0][1] == 'X'){
                xWin = true;
            }else if(grid[0][1] == 'O'){
                oWin = true;
            }
        }
        if(grid[0][2] == grid[1][2] && grid[1][2] == grid[2][2]){
            if(grid[0][2] == 'X'){
                xWin = true;
            }else if(grid[0][2] == 'O'){
                oWin = true;
            }
        }
        if(grid[0][0] == grid[1][1] && grid[1][1] == grid[2][2]){
            if(grid[0][0] == 'X'){
                xWin = true;
            }else if(grid[0][0] == 'O'){
                oWin = true;
            }
        }
        if(grid[0][2] == grid[1][1] && grid[1][1] == grid[2][0]){
            if(grid[0][2] == 'X'){
                xWin = true;
            }else if(grid[0][2] == 'O'){
                oWin = true;
            }
        }
        if((os == xs && !xWin) || (os == xs - 1 && !oWin)){
            printf("yes\n");
        }else{
            printf("no\n");
        }
    }
}
