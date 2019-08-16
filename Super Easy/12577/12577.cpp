#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
    int caseNo = 0;
    char c[6];
    while(scanf("%s", c), strcmp(c, "*")){
        if(!strcmp(c, "Hajj"))
            printf("Case %d: Hajj-e-Akbar\n", ++caseNo);
        else
            printf("Case %d: Hajj-e-Asghar\n", ++caseNo);
    }
}
