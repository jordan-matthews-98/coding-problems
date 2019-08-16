#include<stdio.h>
#include<string.h>

int main(){
    int cases;
    scanf("%d", &cases);
    for(int i = 0; i < cases; i++){
        int left = 0, right = 0;
        char track[150];
        scanf("\n");
        scanf("%[^\n]", track);
        int len = strlen(track);
        if(len != 2)
            for(int j = 1; j < len; j += 3){
                if(track[j-1] == 'M'){
                    --right;
                }else{
                    ++right;
                }
                if(track[j] == 'M'){
                    ++left;
                }else{
                    --left;
                }
            }
        else
            ++left;
        if(left == right){
            printf("LOOP\n");
        }else{
            printf("NO LOOP\n");
        }
    }
}
