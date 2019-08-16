#include <stdio.h>

int main(){
    int N, caseNo = 0, counter, event;

    while(scanf("%d", &N), N){
        counter = 0;
        for(int i = 0; i < N; i++)
            if(scanf("%d", &event), event)
                counter++;
            else
                counter--;
        printf("Case %d: %d\n", ++caseNo, counter);
    }
}
