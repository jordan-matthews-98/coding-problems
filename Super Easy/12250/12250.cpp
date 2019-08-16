#include <stdio.h>
#include <string.h>

using namespace std;

int main(){
    int caseNo = 0;
    char c[256];
    while(scanf("%s", c), strcmp(c, "#")){
        printf("Case %d: ", ++caseNo);
        if(!strcmp(c, "HELLO"))
            printf("ENGLISH\n");
        else if(!strcmp(c, "HOLA"))
            printf("SPANISH\n");
        else if(!strcmp(c, "HALLO"))
            printf("GERMAN\n");
        else if(!strcmp(c, "BONJOUR"))
            printf("FRENCH\n");
        else if(!strcmp(c, "CIAO"))
            printf("ITALIAN\n");
        else if(!strcmp(c, "ZDRAVSTVUJTE"))
            printf("RUSSIAN\n");
        else
            printf("UNKNOWN\n");
    }
}
