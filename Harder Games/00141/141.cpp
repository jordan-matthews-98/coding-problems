#include <stdio.h>
#include <string>
#include <map>

using namespace std;

string calcMinBoard(bool *board, int n){
    string board0 (n * n, '0');
    string board90 (n * n, '0');
    string board180 (n * n, '0');
    string board270 (n * n, '0');
    for(int i = 0; i < n; ++i){
        for(int j = 0; j < n; ++j){
            if(board[i * n + j]){
                board0[i * n + j] = '1';
                board90[j * n + n - 1 - i] = '1';
                board180[(n - 1 - i) * n + (n - 1 - j)] = '1';
                board270[(n - 1 - j) * n + i] = '1';
            }
        }
    }
    if(board0 > board90)
        board0 = board90;
    if(board0 > board180)
        board0 = board180;
    if(board0 > board270)
        return board270;
    return board0;
}

int main(){
    int N;
    while(scanf("%d", &N), N){
        map <string, bool> happened;
        bool board[N*N] = {};
        int endTurn = 0, turn = 1;
        for(int turn = 1, turns = N * 2; turn <= turns; ++turn){
            int r, c;
            scanf("%d %d %*c", &r, &c);
            --r;
            --c;
            board[r * N + c] = !board[r * N + c];
            string s = calcMinBoard(board, N);
            if(happened[s]){
                endTurn = turn;
                while(++turn <= turns){
                    scanf("%*d %*d %*c");
                }
                break;
            }else{
                happened[s] = true;
            }
        }
        if(endTurn)
            printf("Player %d wins on move %d\n", 1 + endTurn % 2, endTurn);
        else
            printf("Draw\n");
    }
}
