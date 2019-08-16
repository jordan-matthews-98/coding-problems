
#include <stdio.h>

int main(){
    char c;
    while(c = getchar(), c != 'E'){
        int len = 1;
        while(getchar() != '\n')
            ++len;
        if(len >= 10){
            printf("4\n");
        }else if(len > 1){
            printf("3\n");
        }else if(c != '1'){
            printf("2\n");
        }else{
            printf("1\n");
        }
    }
}
