#include <stdio.h>
#include <iostream>

using namespace std;

int calcVal(char c){
    if(c == 'X')
        return 10;
    return c - '0';
}

int main(){
    string line;
    while(getline(cin, line), line != "Game Over"){
        int index = 0, frame = 0, score = 0;
        while(++frame < 10){
            if(line[index] == 'X'){
                if(line[index + 4] == 'X'){
                    score += 30;
                }else if(line[index + 4] == '/'){
                    score += 20;
                }else{
                    score += 10 + calcVal(line[index + 2]) + calcVal(line[index + 4]);
                }
                index += 2;
            }else if(line[index + 2] == '/'){
                score += 10 + calcVal(line[index + 4]);
                index += 4;
            }else{
                score += calcVal(line[index]) + calcVal(line[index + 2]);
                index += 4;
            }
        }
        if(line[index + 2] == '/'){
            if(line[index + 4] == 'X'){
                score += 20;
            }else{
                score += 10 + calcVal(line[index + 4]);
            }
        }else if(line[index] == 'X'){
            if(line[index + 2] == 'X'){
                score += 20 + calcVal(line[index + 4]);
            }else if(line[index + 4] == '/'){
                score += 20;
            }else{
                score += 10 + calcVal(line[index + 2]) + calcVal(line[index + 4]);
            }
        }else{
            score += calcVal(line[index]) + calcVal(line[index + 2]);
        }
        printf("%d\n", score);
    }
}
