#include <stdio.h>

int main(){
    int T, N, c, s;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++){
        s = 0;
        scanf("%d", &N);
        while(N--){
            scanf("%d", &c);
            if(c > s)
                s = c;
        }
        printf("Case %d: %d\n", i, s);
    }
}
