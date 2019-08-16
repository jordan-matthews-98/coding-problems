#include <stdio.h>

int main(){
    int words;
    char input[6] = {0};
    scanf("%d", &words);
    for(int i = 0; i < words; i++)
        if(scanf("\n%s", &input), input[4] == 'e'){
            printf("3\n");
            input[4] = 'f';
        }else
            if(input[0] == 't' && input[1] == 'w' ||
               input[0] == 't' && input[2] == 'o' ||
               input[2] == 'o' && input[1] == 'w')
                printf("2\n");
            else
                printf("1\n");
}
