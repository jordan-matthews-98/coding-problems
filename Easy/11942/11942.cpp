#include <stdio.h>

int main(){
    printf("Lumberjacks:\n");
    bool sorted, ascending;
    int N, last, current;
    scanf("%d", &N);
    while(N--){
        int i = 1;
        sorted = true;
        last = 0;
        scanf("%d", &last);
        scanf("%d", &current);
        while(++i < 10 && last == current){
            scanf("%d", &current);
        }
        if(last < current)
            for(; i < 10; i++){
                last = current;
                scanf("%d", &current);
                if(current < last)
                    sorted = false;
            }
        else
            for(; i < 10; i++){
                last = current;
                scanf("%d", &current);
                if(current > last)
                    sorted = false;
            }

        if(sorted)
            printf("Ordered\n");
        else
            printf("Unordered\n");
    }
}
