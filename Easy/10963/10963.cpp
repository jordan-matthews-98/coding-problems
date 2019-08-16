#include <stdio.h>

int main(){
    int cases, W, y1, y2, gap;
    bool yes;
    scanf("%d", &cases);
    while(cases--){
        scanf("%d", &W);
        yes = true;

        if(W > 1){
            scanf("%d %d", &y1, &y2);
            gap = y1 - y2;

            while(--W){
                scanf("%d %d", &y1, &y2);
                if(gap != y1 - y2){
                    --W;
                    yes = false;
                    break;
                }
            }

            while(W--)
                scanf("%*d %*d");
        }

        if(yes)
            printf("yes\n");
        else
            printf("no\n");

        if(cases)
            printf("\n");
    }
}
