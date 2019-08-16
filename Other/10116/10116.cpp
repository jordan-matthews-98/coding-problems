#include <stdio.h>

int main(){
    int r, c, x, y;

    while(scanf("%d %d %d", &r, &c, &x), r){
        r += 2;
        c += 2;
        int steps[r][c] = {}, counter = 0;
        for(int i = 0; i < r; ++i){
            steps[i][0] = -1;
            steps[i][c - 1] = -1;
        }
        for(int j = 0; j < c; ++j){
            steps[0][j] = -1;
            steps[r - 1][j] = -1;
        }
        char grid[r--][c--];
        for(int i = 1; i < r; ++i){
            getchar();
            for(int j = 1; j < c; ++j){
                scanf("%c", &grid[i][j]);
            }
        }
        y = 1;
        while(steps[y][x] == 0){
            steps[y][x] = ++counter;
            switch(grid[y][x]){
                case 'N':
                    --y;
                    break;
                case 'S':
                    ++y;
                    break;
                case 'E':
                    ++x;
                    break;
                case 'W':
                    --x;
                    break;
            }
        }
        if(steps[y][x] == -1){
            printf("%d step(s) to exit\n", counter);
        }else{
            printf("%d step(s) before a loop of %d step(s)\n", --steps[y][x], counter - steps[y][x] + 1);
        }
    }
}
