#include <stdio.h>

int main(){
    int n, n1, n2, n3;
    while(scanf("%d %d %d %d", &n, &n1, &n2, &n3), n|n1|n2|n3)
        printf("%d\n", 1080+9*((40 + n - n1)%40 + (40 + n2 - n1)%40 + (40 + n2 - n3)%40));
}
