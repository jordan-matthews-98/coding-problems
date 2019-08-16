#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
    int N, counter = 0;
    while(scanf("%d", &N), N){
        printf("Game %d:\n", ++counter);
        int code[N], codeCounter[10] = {};
        for(int i = 0; i < N; ++i){
            scanf("%d", code + i);
            ++codeCounter[code[i]];
        }
        do{
            int guess, guessCounter[10] = {}, matches = 0, strongMatches = 0;
            for(int i = 0; i < N; ++i){
                scanf("%d", &guess);
                if(code[i] == guess)
                    ++strongMatches;
                ++guessCounter[guess];
            }
            if(!guess)
                break;
            for(int i = 1; i < 10; ++i)
                matches += min(codeCounter[i], guessCounter[i]);
            printf("    (%d,%d)\n", strongMatches, matches - strongMatches);
        }while(true);
    }
}
