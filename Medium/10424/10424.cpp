#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(){
    char name1[26], name2[26];
    while(scanf("%[^\n]", name1) != EOF){
        float ans;
        int n1 = 0, n2 = 0, len1, len2, sum1 = 0, sum2 = 0, temp;
        len1 = strlen(name1);
        for(int i = 0; i < len1; i++){
            name1[i] = tolower(name1[i]) - 'a' + 1;
            if(name1[i] < 27 && name1[i] > 0)
                sum1 += name1[i];
        }
        while(sum1 > 9){
            temp = 0;
            while(sum1 > 0){
                temp += sum1%10;
                sum1/= 10;
            }
            sum1 = temp;
        }
        scanf("\n%[^\n]", name2);
        len2 = strlen(name2);
        for(int i = 0; i < len2; i++){
            name2[i] = tolower(name2[i]) - 'a' + 1;
            if(name2[i] < 27 && name2[i] > 0)
                sum2 += name2[i];
        }
        while(sum2 > 9){
            temp = 0;
            while(sum2 > 0){
                temp += sum2%10;
                sum2/= 10;
            }
            sum2 = temp;
        }
        if(sum1 < sum2)
            printf("%.2f %%\n",  100.0*sum1/sum2);
        else
            printf("%.2f %%\n",  100.0*sum2/sum1);
        scanf("\n");
    }
}
