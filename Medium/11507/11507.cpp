#include <stdio.h>
#include <string.h>

int main(){
    int L;
    while(scanf("%d", &L), L){
        char direction[3] = "+x", bend[3];
        for(int i = 1; i < L; i++){
            scanf("%s", bend);
            if(strcmp(bend, "No")){
                if(!strcmp(direction, "+x")){
                    if(!strcmp(bend, "+y")){
                        direction[1] = 'y';
                    }else if(!strcmp(bend, "-y")){
                        direction[0] = '-';
                        direction[1] = 'y';
                    }else if(!strcmp(bend, "+z")){
                        direction[1] = 'z';
                    }else{
                        direction[0] = '-';
                        direction[1] = 'z';
                    }
                }else if(!strcmp(direction, "-x")){
                    if(!strcmp(bend, "+y")){
                        direction[1] = 'y';
                    }else if(!strcmp(bend, "-y")){
                        direction[0] = '+';
                        direction[1] = 'y';
                    }else if(!strcmp(bend, "+z")){
                        direction[1] = 'z';
                    }else{
                        direction[0] = '+';
                        direction[1] = 'z';
                    }
                }else if(!strcmp(direction, "+y")){
                    if(!strcmp(bend, "+y")){
                        direction[0] = '-';
                        direction[1] = 'x';
                    }else if(!strcmp(bend, "-y")){
                        direction[1] = 'x';
                    }
                }else if(!strcmp(direction, "-y")){
                    if(!strcmp(bend, "+y")){
                        direction[0] = '+';
                        direction[1] = 'x';
                    }else if(!strcmp(bend, "-y")){
                        direction[1] = 'x';
                    }
                }else if(!strcmp(direction, "+z")){
                    if(!strcmp(bend, "+z")){
                        direction[0] = '-';
                        direction[1] = 'x';
                    }else if(!strcmp(bend, "-z")){
                        direction[1] = 'x';
                    }
                }else{
                    if(!strcmp(bend, "+z")){
                        direction[0] = '+';
                        direction[1] = 'x';
                    }else if(!strcmp(bend, "-z")){
                        direction[1] = 'x';
                    }
                }
            }
        }
        printf("%s\n", direction);
    }
}
