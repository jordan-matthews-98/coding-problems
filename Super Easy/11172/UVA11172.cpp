#include <stdio.h>

int main(){
    int n, n1, n2;
    scanf("%d", &n);
    for(int i = 0; i < n; i++){
        scanf("%d %d", &n1, &n2);
        if(n1 > n2)
            printf(">\n");
        else if(n1 < n2)
            printf("<\n");
        else
            printf("=\n");
    }
}
