#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
    int L;
    while(scanf("%d", &L), L){
        char place, last = 'l';
        int lastLocation, dist = L;
        scanf("\n");
        for(int i = 0; i < L; i++){
            scanf("%c", &place);
            if(place == 'Z'){
                dist = 0;
                scanf("%*[^\n]");
                break;
            }else if(place == 'R'){
                if(last == 'D'){
                    dist = min(dist, i - lastLocation);
                    last = 'R';
                    lastLocation = i;
                }else{
                    last = 'R';
                    lastLocation = i;
                }
            }else if(place == 'D'){
                if(last == 'R'){
                    dist = min(dist, i - lastLocation);
                    last = 'D';
                    lastLocation = i;
                }else{
                    last = 'D';
                    lastLocation = i;
                }
            }
        }
        printf("%d\n", dist);
    }
}
