#include <stdio.h>
#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

struct Rank{
    int handType;
    int highCard;
    Rank(): handType(0), highCard(0){}
};

int getVal(char c){
    switch(c){
        case '2': return 0;
        case '3': return 1;
        case '4': return 2;
        case '5': return 3;
        case '6': return 4;
        case '7': return 5;
        case '8': return 6;
        case '9': return 7;
        case 'T': return 8;
        case 'J': return 9;
        case 'Q': return 10;
        case 'K': return 11;
        case 'A': return 12;
    }
}

bool isFlush(string hand){
    for(int i = 4; i < 16; i+=3)
        if(hand[i] != hand[i-3])
            return false;
    return true;
}

bool isStraight(vector<int> hand){
    int counter = 0;
    if(hand[0] == 0 && hand[4] == 12)
        ++counter;
    for(int i = 1; i < 5; i++){
        if(hand[i-1] == hand[i]-1)
            ++counter;
    }

    return counter == 4;
}
int calcHighCard(vector<int> hand){
    return hand[4]*28561 + hand[3]*2197 + hand[2]*169 + hand[1]*13 + hand[0];
}

void calcRank(vector<int> hand, string handWithSuits, Rank &theRank){
    if(isStraight(hand)){
        if(isFlush(handWithSuits)){
            theRank.handType = 8;
            theRank.highCard = hand[4];
            return;
        }else{
            theRank.handType = 4;
            theRank.highCard = calcHighCard(hand);
        }
    }

    if(hand[0] == hand[3] || hand[1] == hand[4]){
        theRank.handType = 7;
        theRank.highCard = hand[1];
        return;
    }

    if(hand[0] == hand[2]){
        if(hand[3] == hand[4]){
            theRank.handType = 6;
            theRank.highCard = hand[2];
            return;
        }else if(theRank.handType < 3){
            theRank.handType = 3;
            theRank.highCard = hand[2];
        }
    }else if(hand[2] == hand[4]){
        if(hand[0] == hand[1]){
            theRank.handType = 6;
            theRank.highCard = hand[2];
            return;
        }else if(theRank.handType < 3){
            theRank.handType = 3;
            theRank.highCard = hand[2];
        }
    }else if(hand[1] == hand[3] && theRank.handType < 3){
        theRank.handType = 3;
        theRank.highCard = hand[2];
    }

    if(theRank.handType == 4){
        return;
    }else if(isFlush(handWithSuits)){
        theRank.handType = 5;
        theRank.highCard = calcHighCard(hand);
        return;
    }

    if(hand[0] == hand[1]){
        if(hand[2] == hand[3]){
            theRank.handType = 2;
            theRank.highCard = hand[3]*169 + hand[1]*13 + hand[4];
        }else if(hand[3] == hand[4]){
            theRank.handType = 2;
            theRank.highCard = hand[4]*169 + hand[1]*13 + hand[2];
        }else{
            theRank.handType = 1;
            theRank.highCard = hand[1]*2197 + hand[4]*169 + hand[3]*13 + hand[2];
        }
    }else if(hand[1] == hand[2]){
        if(hand[3] == hand[4]){
            theRank.handType = 2;
            theRank.highCard = hand[4]*169 + hand[2]*13 + hand[0];
        }else{
            theRank.handType = 1;
            theRank.highCard = hand[2]*2197 + hand[4]*169 + hand[3]*13 + hand[0];
        }
    }else if(hand[2] == hand[3]){
        theRank.handType = 1;
        theRank.highCard = hand[3]*2197 + hand[4]*169 + hand[1]*13 + hand[0];
    }else if(hand[3] == hand[4]){
        theRank.handType = 1;
        theRank.highCard = hand[4]*2197 + hand[2]*169 + hand[1]*13 + hand[0];
    }else{
        theRank.handType = 0;
        theRank.highCard = calcHighCard(hand);
    }
}

int main(){
    string cards;
    while(getline(cin, cards)){
        vector<int> black(5), white(5);

        for(int i = 0; i < 5; ++i){
            black[i] = getVal(cards[i*3]);
            white[i] = getVal(cards[i*3 + 15]);
        }

        sort(black.begin(), black.end());
        sort(white.begin(), white.end());

        Rank blackRank, whiteRank;
        calcRank(black, cards, blackRank);
        calcRank(white, cards.substr(15, 14), whiteRank);

        if(blackRank.handType > whiteRank.handType)
            printf("Black wins.\n");
        else if(whiteRank.handType > blackRank.handType)
            printf("White wins.\n");
        else
            if(blackRank.highCard > whiteRank.highCard)
                printf("Black wins.\n");
            else if(whiteRank.highCard > blackRank.highCard)
                printf("White wins.\n");
            else
                printf("Tie.\n");
    }
}
