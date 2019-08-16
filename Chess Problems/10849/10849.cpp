#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
    int C;
    scanf("%d", &C);
    while(C--){
        int T, N;
        scanf("%d %d", &T, &N);
        while(T--){
            int r1, c1, r2, c2;
            scanf("%d %d %d %d", &r1, &c1, &r2, &c2);
            int rDif = abs(r1 - r2);
            int cDif = abs(c1 - c2);
            if(rDif == cDif){
                if(rDif == 0)
                    printf("0\n");
                else
                    printf("1\n");
            }else if(rDif % 2 == cDif % 2)
                printf("2\n");
            else{
                printf("no move\n");
            }
        }
    }
}
