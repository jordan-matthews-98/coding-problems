#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
    int N, B;
    while(scanf("%d %d", &N, &B), N){
        int balls[B];
        bool yes = true, arr[N + 1] = {};
        for(int i = 0; i < B; ++i){
            scanf("%d", balls + i);
            for(int j = 0; j < i; ++j){
                arr[abs(balls[j] - balls[i])] = true;
            }
        }
        for(int i = 1; i <= N; ++i){
            if(!arr[i]){
                yes = false;
                break;
            }
        }
        if(yes)
            printf("Y\n");
        else
            printf("N\n");
    }
}
