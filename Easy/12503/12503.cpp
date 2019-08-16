#include <stdio.h>
#include <string.h>

int main(){
    int T, n, same, position;

    char c[6];

    scanf("%d", &T);
    while(T--){
        scanf("%d", &n);
        int instruction[n];
        position = 0;
        for(int i = 0; i < n; i++){
            scanf("%s", c);
            if(!strcmp(c, "SAME")){
                scanf("%*s %d", &same);
                instruction[i] = instruction[same - 1];
            }else if(!strcmp(c, "LEFT"))
                instruction[i] = -1;
            else
                instruction[i] = 1;
            position += instruction[i];
        }
        printf("%d\n", position);
    }
}
