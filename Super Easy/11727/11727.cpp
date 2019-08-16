#include <stdio.h>

int main(){
    int T, n1, n2, n3;

    scanf("%d", &T);
    for(int i = 1; i <= T; i++){
        scanf("%d %d %d", &n1, &n2, &n3);
        if(n1 > n2)
            if(n2 > n3)
                printf("Case %d: %d\n", i, n2);
            else if(n3 > n1)
                printf("Case %d: %d\n", i, n1);
            else
                printf("Case %d: %d\n", i, n3);
        else
            if(n2 < n3)
                printf("Case %d: %d\n", i, n2);
            else if(n3 < n1)
                printf("Case %d: %d\n", i, n1);
            else
                printf("Case %d: %d\n", i, n3);
    }
}
