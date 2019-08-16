#include <stdio.h>
#include <string.h>

int main(){
    int ans;
    char n[11], c = '0';
    while(scanf("%s", n), strcmp(n, "0")){
        ans = 0;
        for(int i = 0; n[i]; ++i)
            ans += n[i] - c;
        if(ans >= 10)
            ans = ans/10 + ans%10;
        printf("%d\n", ans/10 + ans%10);
    }
}
