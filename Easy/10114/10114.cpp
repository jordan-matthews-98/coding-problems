#include <stdio.h>

int main(){
    int months, remainingRecords, month, nextRecord;
    double downPayment, loan, owed, worth, depreciation, nextDepreciation, payment;

    while(scanf("%d %lf %lf %d", &months, &downPayment, &loan, &remainingRecords), months >= 0){
        scanf("%d %lf", &nextRecord, &depreciation);
        month = 0;
        owed = loan;
        payment = loan/months;
        worth = (downPayment + loan)*(1 - depreciation);

        if(--remainingRecords){
            scanf("%d %lf", &nextRecord, &nextDepreciation);
            --remainingRecords;
        }else{
            nextRecord = months;
        }

        while(worth <= owed){
            owed -= payment;
            if(++month < nextRecord){
                worth *= (1 - depreciation);
            }else{
                depreciation = nextDepreciation;
                if(remainingRecords){
                    scanf("%d %lf", &nextRecord, &nextDepreciation);
                    worth *= (1 - depreciation);
                    --remainingRecords;
                }else{
                    nextRecord = months;
                    worth *= (1 - depreciation);
                }
            }
        }

        while(remainingRecords--)
            scanf("%*d %*f");

        if(month == 1)
            printf("1 month\n");
        else
            printf("%d months\n", month);
    }
}
