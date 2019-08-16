#include <stdio.h>

bool bingo(bool card[5][5]){
    bool bingo;
    for(int i = 0; i < 5; ++i){
        bingo = true;
        for(int j = 0; j < 5; ++j){
            bingo &= card[i][j];
        }
        if(bingo)
            return true;
        bingo = true;
        for(int j = 0; j < 5; ++j){
            bingo &= card[j][i];
        }
        if(bingo)
            return true;
    }
    bingo = true;
    for(int i = 0; i < 5; ++i){
        bingo &= card[i][i];
    }
    if(bingo)
        return true;
    bingo = true;
    for(int i = 0; i < 5; ++i){
        bingo &= card[i][4 - i];
    }
    return bingo;
}

int main(){
    int n;
    scanf("%d", &n);
    while(n--){
        int cardNums[5][5] = {};
        for(int i = 0; i < 5; ++i){
            for(int j = 0; j < 5; ++j){
                if(i == 2 && j == 2)
                    continue;
                scanf("%d", &cardNums[i][j]);
            }
        }
        int bingoNums[75];
        for(int i = 0; i < 75; ++i){
            scanf("%d", bingoNums + i);
        }
        int counter = 0;
        bool card[5][5] = {};
        card[2][2] = true;
        do{
            for(int i = 0; i < 5; ++i){
                for(int j = 0; j < 5; ++j){
                    if(cardNums[i][j] == bingoNums[counter]){
                        card[i][j] = true;
                    }
                }
            }
            ++counter;
        }while(!bingo(card));
        printf("BINGO after %d numbers announced\n", counter);
    }
}
