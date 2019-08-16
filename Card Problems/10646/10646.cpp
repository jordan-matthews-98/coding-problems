/*
#include<stdio.h>
int main(){int t,n;scanf("%d",&t);for(int n=1;n<=t;++n){char d[156];scanf("\n%[^\n]",d);printf("Case %d: %c%c\n",n,d[96],d[97]);}}
*/
#include <stdio.h>

int main(){
    int testCases;
    scanf("%d", &testCases);
    for(int caseNo = 1; caseNo <= testCases; caseNo++){
        char deck[156];
        int X, Y = 0, it = 78;
        scanf("\n%[^\n]", deck);
        for(int i = 0; i < 3; i++){
            if(deck[it] > '9'){
                Y += 30;
                it -= 3;
            }else{
                Y += 3*(deck[it] - '0');
                it -= 3*(11 - deck[it] + '0');
            }
        }
        printf("Case %d: %c%c\n", caseNo, deck[75+(Y-it)], deck[75+(Y-it)+1]);
    }
}
