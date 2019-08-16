#include <stdio.h>

int main(){
    int n, k, testNo = 0;
    while(scanf("%d", &n), n){
        scanf("%d", &k);
        int wins[n+1] = {}, losses[n+1] = {};
        k = k*n*(n-1)/2;
        while(k--){
            int p1, p2;
            char m1[9], m2[9];
            scanf("%d %s %d %s", &p1, m1, &p2, m2);
            if((m1[0] == 'r' && m2[0] == 's') || (m1[0] == 's' && m2[0] == 'p') || (m1[0] == 'p' && m2[0] == 'r')){
                ++wins[p1];
                ++losses[p2];
            }else if(m1[0] != m2[0]){
                ++wins[p2];
                ++losses[p1];
            }
        }
        if(testNo++)
            printf("\n");
        for(int i = 1; i <= n; ++i){
            if(wins[i] + losses[i])
                printf("%.3lf\n", wins[i]*1.0/(wins[i] + losses[i]));
            else
                printf("-\n");
        }
    }
}
