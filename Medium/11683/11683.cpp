#include <stdio.h>

int main(){
    int A;

    while(scanf("%d", &A), A){
        int C, current, blocks = 0;
        scanf("%d", &C);
        while(C--){
            scanf("%d", &current);
            if(current < A){
                blocks += (A - current);
                A = current;
            }else{
                A = current;
            }
        }
        printf("%d\n", blocks);
    }
}
