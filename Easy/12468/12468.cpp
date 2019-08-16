#include <stdio.h>
#include <algorithm>

int main(){
    int a, b, ans;
    while(scanf("%d %d", &a, &b), a != -1){
        ans = abs(a - b);
        if(ans > 50)
            ans = 100 - ans;
        printf("%d\n", ans);
    }
}
