#include <stdio.h>

int main() {
    int n;
    char *c, temp;
    while(scanf("%d", &n) != EOF){
        printf("%d converts to ", n);
        c = (char *)&n;
        temp = c[0];
        c[0] = c[3];
        c[3] = temp;
        temp = c[1];
        c[1] = c[2];
        c[2] = temp;
        printf("%d\n", n);
    }
}
