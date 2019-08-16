#include <stdio.h>

int main(){
    int tests;
    scanf("%d", &tests);
    for(int testNo = 0; testNo < tests; ++testNo){
        int r, c, n;
        scanf("%d %d %d", &r, &c, &n);
        char grid[r + 2][c + 2] = {}, gridCopy[r + 2][c + 2] = {};
        for(int i = 1; i <= r; ++i){
            getchar();
            for(int j = 1; j <= c; ++j){
                scanf("%c", &grid[i][j]);
            }
        }
        for(int i = 0; i < n; ++i){
            for(int j = 1; j <= r; ++j){
                for(int k = 1; k <= c; ++k){
                    gridCopy[j][k] = grid[j][k];
                }
            }
            for(int j = 1; j <= r; ++j){
                for(int k = 1; k <= c; ++k){
                    if(grid[j][k] == 'R'){
                        if(gridCopy[j - 1][k] == 'P' || gridCopy[j + 1][k] == 'P' || gridCopy[j][k - 1] == 'P' || gridCopy[j][k + 1] == 'P'){
                            grid[j][k] = 'P';
                        }
                    }else if(grid[j][k] == 'P'){
                        if(gridCopy[j - 1][k] == 'S' || gridCopy[j + 1][k] == 'S' || gridCopy[j][k - 1] == 'S' || gridCopy[j][k + 1] == 'S'){
                            grid[j][k] = 'S';
                        }
                    }else{
                        if(gridCopy[j - 1][k] == 'R' || gridCopy[j + 1][k] == 'R' || gridCopy[j][k - 1] == 'R' || gridCopy[j][k + 1] == 'R'){
                            grid[j][k] = 'R';
                        }
                    }
                }
            }
        }
        if(testNo)
            printf("\n");
        for(int i = 1; i <= r; ++i){
            for(int j = 1; j <= c; ++j){
                printf("%c", grid[i][j]);
            }
            printf("\n");
        }
    }
}
