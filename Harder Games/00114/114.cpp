#include <stdio.h>

int main(){
    int m, n, wCost, p;
    scanf("%d%d%d%d", &m, &n, &wCost, &p);
    bool bumpGrid[n][m] = {};
    int x, y, val, cost, valGrid[n][m] = {}, costGrid[n][m] = {};
    for(int i = 0; i < p; ++i){
        scanf("%d%d%d%d", &x, &y, &val, &cost);
        valGrid[--y][--x] = val;
        costGrid[y][x] = cost;
        bumpGrid[y][x] = true;
    }
    --n;
    for(int i = 0; i < m; ++i){
        bumpGrid[0][i] = true;
        bumpGrid[n][i] = true;
        costGrid[0][i] = wCost;
        costGrid[n][i] = wCost;
    }
    --m;
    for(int i = 1; i < n; ++i){
        bumpGrid[i][0] = true;
        bumpGrid[i][m] = true;
        costGrid[i][0] = wCost;
        costGrid[i][m] = wCost;
    }
    int direction, life, sum = 0;
    while(scanf("%d%d%d%d", &x, &y, &direction, &life) == 4){
        --x;
        --y;
        int ballSum = 0;
        while(life > 0){
            switch(direction){
            case 0:
                while(--life && !bumpGrid[y][++x]);
                if(life){
                    ballSum += valGrid[y][x];
                    life -= costGrid[y][x--];
                    direction = 3;
                }
                break;
            case 1:
                while(--life && !bumpGrid[++y][x]);
                if(life){
                    ballSum += valGrid[y][x];
                    life -= costGrid[y--][x];
                    direction = 0;
                }
                break;
            case 2:
                while(--life && !bumpGrid[y][--x]);
                if(life){
                    ballSum += valGrid[y][x];
                    life -= costGrid[y][x++];
                    direction = 1;
                }
                break;
            case 3:
                while(--life && !bumpGrid[--y][x]);
                if(life){
                    ballSum += valGrid[y][x];
                    life -= costGrid[y++][x];
                    direction = 2;
                }
                break;
            }
        }
        printf("%d\n", ballSum);
        sum += ballSum;
    }
    printf("%d\n", sum);
}
