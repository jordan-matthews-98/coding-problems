#include <stdio.h>
#include <string.h>

int main(){
    int T;
    char oudlers[3][50] = {"fool", "twenty-one of trumps", "one of trumps"};
    scanf("%d", &T);
    for(int i = 1; i <= T; i++){
        int M, counter = 0, points = 0, oPoints;
        char card[50];
        scanf("%d", &M);
        while(M--){
            scanf("\n%[^\n]", card);
            if(!(strcmp(card, oudlers[0]) && strcmp(card, oudlers[1]) && strcmp(card, oudlers[2]))){
                counter++;
                points += 9;
            }else if(card[0] == 'k' && card[1] == 'i' && card[2] == 'n' && card[3] == 'g'){
                points += 9;
            }else if(card[0] == 'q' && card[1] == 'u' && card[2] == 'e' && card[3] == 'e' && card[4] == 'n'){
                points += 7;
            }else if(card[0] == 'k' && card[1] == 'n' && card[2] == 'i' && card[3] == 'g' && card[4] == 'h' && card[5] == 't'){
                points += 5;
            }else if(card[0] == 'j' && card[1] == 'a' && card[2] == 'c' && card[3] == 'k'){
                points += 3;
            }else{
                ++points;
            }
        }
        if(counter == 0){
            oPoints = 56;
        }else if(counter == 1){
            oPoints = 51;
        }else if(counter == 2){
            oPoints = 41;
        }else if(counter == 3){
            oPoints = 36;
        }
        points /= 2;
        printf("Hand #%d\n", i);
        if(points >= oPoints){
            printf("Game won by %d point(s).\n", points - oPoints);
        }else{
            printf("Game lost by %d point(s).\n", oPoints - points);
        }
        if(i != T){
            printf("\n");
        }
    }
}
