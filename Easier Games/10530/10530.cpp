#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){
    int guess;
    while(scanf("%d", &guess), guess){
        bool honest;
        int lo = 0, hi = 11;
        string transcript;
        getchar();
        getline(cin, transcript);
        while(transcript[4] != 't'){
            if(transcript[4] == 'l'){
                lo = max(guess, lo);
            }else{
                hi = min(guess, hi);
            }
            scanf("%d", &guess);
            getchar();
            getline(cin, transcript);
        }
        if(guess < hi && guess > lo)
            printf("Stan may be honest\n");
        else
            printf("Stan is dishonest\n");
    }
}
