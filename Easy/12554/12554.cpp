#include <stdio.h>
#include <string>

using namespace std;

int main(){
    char c[100][101];
    string song[16];
    int n;

    for(int i = 0; i < 13; ++i){
        song[i] = "Happy";
        song[++i] = "birthday";
        song[++i] = "to";
        song[++i] = "you";
    }

    song[11] = "Rujia";

    scanf("%d", &n);

    for(int i = 0; i < n; i++){
        scanf("%s", c[i]);
    }

    for(int i = 0; i < n; i+=16){
        for(int j = 0; j < 16; j++){
            printf("%s: %s\n", c[(i + j)%n], song[j].c_str());
        }
    }
}
