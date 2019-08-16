#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
    int rolls[1000] = {}, numRolls = 0;
    while(scanf("%d", rolls + numRolls), rolls[numRolls++]);
    int numPlayers;
    while(scanf("%d", &numPlayers), numPlayers){
        int from, to, movement[100] = {};
        while(scanf("%d%d", &from, &to), from){
            movement[from] = to;
        }
        int extraTurn[100] = {};
        while(scanf("%d", &from), from){
            if(from < 0){
                extraTurn[0 - from] = -1;
            }else{
                extraTurn[from] = 1;
            }
        }
        int position[numPlayers] = {}, playerTurn[numPlayers] = {};

        int turn = 0;
        numRolls = 0;
        while(1){
            if(turn >= numPlayers){
                turn = 0;
            }
            if(playerTurn[turn] == 1){
                playerTurn[turn] = 0;
                ++turn;
                continue;
            }
            position[turn] += rolls[numRolls++];
            if(position[turn] == 100){
                printf("%d\n", turn + 1);
                break;
            }else if(position[turn] > 100){
                position[turn] -= rolls[numRolls - 1];
                ++turn;
                continue;
            }
            if(extraTurn[position[turn]] == -1){
                playerTurn[turn] = 1;
                ++turn;
                continue;
            }else if(extraTurn[position[turn]] == 1){
                continue;
            }
            if(movement[position[turn]]){
                position[turn] = movement[position[turn]];
                ++turn;
                continue;
            }
            ++turn;
        }
    }
}
