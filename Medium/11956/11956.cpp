#include <stdio.h>
#include <string.h>
#include <iostream>
#include <iomanip>

using namespace std;

int main(){
    int T;
    scanf("%d", &T);

    for(int i = 1; i <= T; i++){
        char c[100001];
        scanf("\n%[^\n]", c);
        int bytes[100] = {0}, pointer = 0;
        for(int j = 0, len = strlen(c); j < len; j++){
            switch(c[j]){
            case '>':
                ++pointer;
                pointer %= 100;
                break;
            case '<':
                pointer += 99;
                pointer %= 100;
                break;
            case '+':
                ++bytes[pointer];
                bytes[pointer] %= 256;
                break;
            case '-':
                bytes[pointer] += 255;
                bytes[pointer] %= 256;
                break;
            default:
                break;
            }
        }
        printf("Case %d:", i);
        for(int j = 0; j < 100; j++){
            printf(" %02X", bytes[j]);
        }
        printf("\n");
    }
}
