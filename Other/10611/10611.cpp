#include <stdio.h>
#include <algorithm>

using namespace std;

int main(){
    int numLadies, numLuchus;
    scanf("%d", &numLadies);

    int ladiesHeights[numLadies];
    for(int i = 0; i < numLadies; ++i){
        scanf("%d", &ladiesHeights[i]);
    }
    scanf("%d", &numLuchus);

    while(numLuchus--){
        int luchuHeight, lady;
        scanf("%d", &luchuHeight);

        lady = lower_bound(ladiesHeights, ladiesHeights + numLadies, luchuHeight) - ladiesHeights - 1;
        if(lady >= 0)
            printf("%d ", ladiesHeights[lady]);
        else
            printf("X ");

        lady = upper_bound(ladiesHeights, ladiesHeights + numLadies, luchuHeight) - ladiesHeights;
        if(lady < numLadies)
            printf("%d\n", ladiesHeights[lady]);
        else
            printf("X\n");
    }
}
