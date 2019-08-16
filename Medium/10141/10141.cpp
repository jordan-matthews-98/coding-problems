#include <stdio.h>
#include <string.h>

int main(){
    char name[81], bestName[81];
    int n, p, caseNo = 0, metRequirements, bestMetRequirements;
    float price, bestPrice;

    while(scanf("%d %d", &n, &p), n != 0){
        while(n--)
            scanf("\n%*[^\n]");

        scanf("\n%[^\n]%f %d", bestName, &bestPrice, &bestMetRequirements);

        for(int i = 0; i < bestMetRequirements; i++)
            scanf("\n%*[^\n]");
        while(--p){
            scanf("\n%[^\n]%f %d", name, &price, &metRequirements);
            if(metRequirements > bestMetRequirements){
                bestMetRequirements = metRequirements;
                bestPrice = price;
                strcpy(bestName, name);
            }else if(metRequirements == bestMetRequirements && price < bestPrice){
                bestMetRequirements = metRequirements;
                bestPrice = price;
                strcpy(bestName, name);
            }
            while(metRequirements--)
                scanf("\n%*[^\n]");
        }
        if(caseNo)
            printf("\n");
        printf("RFP #%d\n%s\n", ++caseNo, bestName);
    }
}
