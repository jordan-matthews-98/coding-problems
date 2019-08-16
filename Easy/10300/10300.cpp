#include <stdio.h>

int main(){
    int n, f, land, eco, premium;

    scanf("%d", &n);
    while(n--){
        premium = 0;
        scanf("%d", &f);
        while(f--){
            scanf("%d %*d %d", &land, &eco);
            premium += land*eco;
        }
        printf("%d\n", premium);
    }
}
