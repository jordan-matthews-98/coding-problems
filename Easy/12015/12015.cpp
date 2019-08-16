#include <stdio.h>

int main(){
    char c[10][101];
    int T, highest, current, bitmask;

    scanf("%d", &T);
    for(int i = 1; i <= T; i++){
        bitmask = 1;
        scanf("%s %d", c[0], &highest);
        for(int j = 1; j < 10; j++){
            scanf("%s %d", c[j], &current);
            if(current > highest){
                bitmask = (1 << j);
                highest = current;
            }else if(current == highest)
                bitmask |= (1 << j);
        }
        printf("Case #%d:\n", i);
        for(int j = 0; j < 10; j++)
            if(bitmask & (1 << j))
                printf("%s\n", c[j]);
    }
}
