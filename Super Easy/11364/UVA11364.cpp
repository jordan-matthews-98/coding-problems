#include <stdio.h>

int main() {
    int cases, stores, location, min, max;
    scanf("%d", &cases);
    for(int i = 0; i < cases; i++){
        scanf("%d", &stores);
        min = 99;
        max = 0;
        for(int j = 0; j < stores; j++){
            scanf("%d", &location);
            if(location < min)
                min = location;
            if(location > max)
                max = location;
        }
        printf("%d\n", (max - min)*2);
    }
}
