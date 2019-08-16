#include <stdio.h>

int main() {
    int cases, xAxis, yAxis, x, y;

    while(scanf("%d", &cases), cases){
        scanf("%d %d", &xAxis, &yAxis);

        for(int i = 0; i < cases; i++){
            scanf("%d %d", &x, &y);

            if(y == yAxis || x == xAxis)
                printf("divisa\n");
            else if(y > yAxis)
                if(x > xAxis)
                    printf("NE\n");
                else
                    printf("NO\n");
            else if(y < yAxis)
                if(x > xAxis)
                    printf("SE\n");
                else
                    printf("SO\n");
        }
    }
}
