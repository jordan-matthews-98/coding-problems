#include<stdio.h>
#include <string.h>

main(){
    int caseNo = 0, arr[1000001];
    char s[1000001];
    while(gets(s)){
        int len = strlen(s);
        memset(arr, 0, sizeof(arr));

        for(int i = 1; i < len; i++)
            if(s[i] == s[i - 1])
                arr[i] = arr[i - 1];
            else
                arr[i] = arr[i - 1] + 1;

        int i, j, n;
        printf("Case %d:\n", ++caseNo);
        scanf("%d",&n);

        while(n--)
        {
            scanf("%d%d",&i,&j);

            if(arr[i] == arr[j])
                printf("Yes\n");
            else
                printf("No\n");
        }
        getchar();
    }
}
