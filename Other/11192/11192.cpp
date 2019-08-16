#include <stdio.h>
#include <string.h>

int main(){
    int T;
    scanf("%d", &T);

    for(int i = 1; i <= T; i++){
        char c[100001];
        scanf("\n%[^\n]", c);
        int bytes[100] = {0}, pointer = 0;
        for(int j = 0, len = strlen(c); j < len; j++)
            if(c[j] == '+')
                ++bytes[pointer];
            else if(c[j] == '>')
                pointer = (pointer + 1) % 100;
            else if(c[j] == '<')
                pointer = (pointer + 99) % 100;
            else if(c[j] == '-')
                bytes[pointer] += 255;
        printf("Case %d:", i);
        for(int j = 0; j < 100; j++)
            printf(" %02X", bytes[j]%256);
        printf("\n");
    }
}
