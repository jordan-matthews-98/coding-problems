#include<stdio.h>

int main(){
    char values[13][6] = {"2", "3", "4", "5", "6", "7", "8", "9", "10", "Jack", "Queen", "King", "Ace"};
    char suits[4][9] = {"Clubs", "Diamonds", "Hearts", "Spades"};
    int testCases;
    scanf("%d", &testCases);
    while(testCases){
        int n;
        scanf("%d", &n);
        int shuffles[n][52];
        for(int i = 0; i < n; ++i){
            for(int j = 0; j < 52; ++j){
                scanf("%d", &shuffles[i][j]);
                --shuffles[i][j];
            }
        }
        char c;
        bool whichDeck = 0;
        int deck[2][52];
        for(int i = 0; i < 52; ++i){
            deck[0][i] = i;
        }
        while(n--){
            int shuffle;
            scanf("%d", &shuffle);
            whichDeck = !whichDeck;
            for(int i = 0; i < 52; ++i){
                deck[whichDeck][i] = deck[!whichDeck][shuffles[shuffle-1][i]];
            }
        }
        for(int i = 0; i < 52; i++){
            printf("%s of %s\n", values[deck[whichDeck][i]%13], suits[deck[whichDeck][i]/13]);
        }
        if(--testCases)
            printf("\n");
    }
}
