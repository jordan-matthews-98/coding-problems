#include <stdio.h>

using namespace std;

int main(){
    int counter = 2, lastLucky, luckyNum;
    bool luckies[2000001] = {false}, changed = true;
    for(int i = 0; i < 2000001; i+=2){
        luckies[i] = true;
    }
    int n = 3;
    //printf("indexOfN: %d\nn:%d\n\n", counter, n);
    while(++counter, n < 1000000 && changed){
        changed = false;
        luckyNum = 0;
        for(int i = 1; i < 2000001; ++i){
            if(!luckies[i]){
                ++luckyNum;
                if(!(luckyNum%n)){
                    changed = true;
                    luckies[i] = true;
                }
            }
        }
        luckyNum = 0;
        for(int i = 1; i < 2000001; ++i){
            if(!luckies[i]){
                ++luckyNum;
                if(luckyNum%counter == 0){
                    n = i;
                    break;
                }
            }
        }
        if(!(counter%100))printf("indexOfN: %d\nn:%d\n\n", counter, n);
    }
    printf("indexOfN: %d\nn:%d\n\n", counter, n);
    counter = 0;
    for(int i = 0; i < 2000001; ++i){
        if(!luckies[i]){
            counter++;
        }
    }
    for(int i = 2000000; i >= 0; --i){
        if(!luckies[i])
            lastLucky = luckies[i];
    }
    printf("%d %d\n", counter, lastLucky);
}
