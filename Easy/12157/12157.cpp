#include <stdio.h>

int main(){
    int T, N, mile, juice, time;
    scanf("%d", &T);
    for(int i = 1; i <= T; i++){
        mile = 0;
        juice = 0;
        scanf("%d", &N);
        while(N--){
            scanf("%d", &time);
            mile += time/30*10+10;
            juice += time/60*15+15;
        }
        if(mile < juice)
            printf("Case %d: Mile %d\n", i, mile);
        else if(juice < mile)
            printf("Case %d: Juice %d\n", i, juice);
        else
            printf("Case %d: Mile Juice %d\n", i, mile);
    }
}
