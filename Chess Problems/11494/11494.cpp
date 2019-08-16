#include <stdio.h>
#include <algorithm>

int main(){
    int x1, y1, x2, y2;
    while(scanf("%d %d %d %d", &x1, &y1, &x2, &y2), x1){
        int xDif = abs(x1 - x2);
        int yDif = abs(y1 - y2);
        if(xDif == yDif){
            if(xDif == 0){
                printf("0\n");
            }else{
                printf("1\n");
            }
        }else if(xDif == 0 || yDif == 0){
            printf("1\n");
        }else{
            printf("2\n");
        }
    }
}
