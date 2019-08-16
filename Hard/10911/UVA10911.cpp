#include <stdio.h>
#include <math.h>
#include <algorithm>

using namespace std;

double dist[16][16], matches[1 << 16];
int N, doneMatching;

double match(int mask){
    if(matches[mask] != -1)
        return matches[mask];
    if(mask == doneMatching)
        return matches[mask] = 0;

    double sum = 2e9;
    int house1, house2;

    for(house1 = 0; house1 < N; house1++)
        if((mask & (1 << house1)) == 0)
            break;

    for(house2 = house1 + 1; house2 < N; house2++)
        if((mask & (1 << house2)) == 0)
            sum = min(sum, dist[house1][house2] + match(mask | (1 << house1) | (1 << house2)));

    return matches[mask] = sum;
}

int main(){
    int x[16], y[16], caseNo = 0;
    while(scanf("%d", &N), N){
        N *= 2;

        for(int i = 0; i < N; i++)
            scanf("%*s %d %d", &x[i], &y[i]);

        for(int i = 0; i < N - 1; i++)
            for(int j = i + 1; j < N; j++)
                dist[i][j] = dist[j][i] = hypot(x[i] - x[j], y[i] - y[j]);

        for(int i = 0; i < (1 << 16); i++)
            matches[i] = -1;

        doneMatching = (1 << N) - 1;
        printf("Case %d: %.2lf\n", ++caseNo, match(0));
    }
    return 0;
}
