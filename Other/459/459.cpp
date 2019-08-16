#include <stdio.h>
#include <iostream>
#include <algorithm>

using namespace std;

int main(){

    int t;
    scanf("%d", &t);

    while(t--){
        int numGraphs, subgraphs, graphs[26] = {};
        char c;
        string edge;
        scanf("\n%c", &c);
        getchar();
        numGraphs = subgraphs = c - 'A' + 1;
        for(int i = 0; i < numGraphs; ++i)
            graphs[i] = (1 << i);

        while(getline(cin, edge), edge != ""){
            int v1 = edge[0] - 'A';
            int v2 = edge[1] - 'A';
            if(!(graphs[v1] & (1 << v2))){
                graphs[v1] |= graphs[v2];
                for(int i = 0; i < numGraphs; ++i)
                    if(graphs[i] & (1 << v1))
                        graphs[i] = graphs[v1];
                --subgraphs;
            }
        }
        printf("%d\n", subgraphs);
        if(t)
            printf("\n");
    }
}
