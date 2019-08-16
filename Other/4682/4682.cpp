#include <stdio.h>

int main(){
    int T;
    scanf("%d", &T);

    while(T--){
        int N;
        scanf("%d", &N);
        int sums[N], mx = 0;
        for(int i = 0; i < N; ++i){
            scanf("%d", sums + i);
            if(sums[i] > mx)
                mx = sums[i];
        }
        for(int i = 1; i < N; ++i){
            for(int j = 0; j < i; ++j){
                sums[j] ^= sums[i];
                if(sums[j] > mx)
                    mx = sums[j];
            }
        }
        printf("%d\n", mx);
    }
}
