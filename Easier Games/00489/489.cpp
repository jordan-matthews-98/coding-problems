#include <stdio.h>
#include <iostream>

using namespace std;

int main(){
    int round;
    while(scanf("%d", &round), round != -1){
        printf("Round %d\n", round);
        string answer, guess;
        getchar();
        getline(cin, answer);
        getline(cin, guess);
        int ansMask = 0, guessMask = 0, countDown = 7;
        for(int i = 0, len = answer.length(); i < len; ++i)
            ansMask |= (1 << (answer[i] - 'a'));
        for(int i = 0, len = guess.length(); i < len && countDown; ++i){
            if(!(ansMask & (1 << (guess[i] - 'a'))))
                if(!(guessMask & (1 << (guess[i] - 'a'))))
                    --countDown;
            guessMask |= (1 << (guess[i] - 'a'));
        }
        if((ansMask & guessMask) == ansMask){
            printf("You win.\n");
        }else{
            if(!countDown)
                printf("You lose.\n");
            else
                printf("You chickened out.\n");
        }
    }
}
