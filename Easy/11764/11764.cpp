#include <stdio.h>

int main(){
    int T, N, highJumps, lowJumps, currentWall, nextWall;
    scanf("%d", &T);

    for(int i = 1; i <= T; i++){
        highJumps = 0;
        lowJumps = 0;
        scanf("%d", &N);
        scanf("%d", &currentWall);
        while(--N){
            scanf("%d", &nextWall);
            if(currentWall > nextWall)
                lowJumps++;
            else if(currentWall < nextWall)
                highJumps++;
            currentWall = nextWall;
        }
        printf("Case %d: %d %d\n", i, highJumps, lowJumps);
    }
}
