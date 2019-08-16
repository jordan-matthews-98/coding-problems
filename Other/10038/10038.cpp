#include <stdio.h>
#include <algorithm>

int main(){
    int n;
    while(scanf("%d", &n) != EOF){
        bool arr[n] = {1}, jolly = true;
        int n1, n2, dif, i = n;

        scanf("%d", &n1);
        while(--i){
            scanf("%d", &n2);
            dif = abs(n1 - n2);
            if(dif < n && !arr[dif])
                arr[dif] = true;
            else{
                jolly = false;
                break;
            }
            n1 = n2;
        }

        while(--i > 0)
            scanf("%*d");

        if(jolly){
            printf("Jolly\n");
        }else{
            printf("Not jolly\n");
        }
    }
}
