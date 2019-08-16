#include <stdio.h>

int main(){
    int B, N, D, C, V;
    while(scanf("%d %d", &B, &N), B && N){
        int R[B];
        for(int i = 0; i < B; i++)
            scanf("%d", &R[i]);

        for(int i = 0; i < N; i++){
            scanf("%d %d %d", &D, &C, &V);
            R[D - 1] -= V;
            R[C - 1] += V;
        }

        for(int i = 0; i < B; i++)
            if(R[i] < 0)
                V = 0;

        if(V)
            printf("S\n");
        else
            printf("N\n");
    }
}
