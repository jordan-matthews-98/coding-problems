#include <stdio.h>

int main(){
    bool stayHome;
    int N, B, H, W, p ,a, bestCost;
    while(scanf("%d %d %d %d", &N, &B, &H, &W) != EOF){
        bestCost = B + 1;
        while(H--){
            scanf("%d", &p);
            p *= N;
            if(p <= B)
                for(int i = 0; i < W; ++i){
                    scanf("%d", &a);
                    if(a >= N && p < bestCost)
                        bestCost = p;
                }
            else
                for(int i = 0; i < W; ++i)
                    scanf("%*d");
        }
        if(bestCost <= B)
            printf("%d\n", bestCost);
        else
            printf("stay home\n");
    }
}
