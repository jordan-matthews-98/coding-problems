#include <stdio.h>
#include <string.h>

int main(){
    int t;
    scanf("%d", &t);
    while(t--){
        int temp, players, specials, rolls, moveTo[101] = {};
        scanf("%d %d %d", &players, &specials, &rolls);
        if(!players){
            for(int i = 0; i < specials; ++i)
                scanf("%*d %*d");
            for(int i = 0; i < rolls; ++i)
                scanf("%*d");
            continue;
        }
        while(specials--){
            scanf("%d", &temp);
            scanf("%d", moveTo + temp);
        }
        int positions[players];
        for(int i = 0; i < players; ++i){
            positions[i] = 1;
        }
        int i;
        for(i = 0; i < rolls; ++i){
            scanf("%d", &temp);
            positions[i % players] += temp;

            if(moveTo[positions[i % players]])
                positions[i % players] = moveTo[positions[i % players]];

            if(positions[i % players] >= 100){
                positions[i % players] = 100;
                break;
            }
        }
        while(++i < rolls){
            scanf("%*d");
        }
        for(i = 0; i < players; ++i){
            printf("Position of player %d is %d.\n", i + 1, positions[i]);
        }
    }
}
