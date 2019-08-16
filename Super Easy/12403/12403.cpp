#include<stdio.h>
#include<string.h>

int main(){
    int T, donation, cash = 0;
    char c[7];
    scanf("%d", &T);
    for(int i = 0; i < T; i++){
        scanf("%s", c);
        if(!strcmp(c, "donate")){
            scanf("%d", &donation);
            cash += donation;
        }else
            printf("%d\n", cash);
    }
}
