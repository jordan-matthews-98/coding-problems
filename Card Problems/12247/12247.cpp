#include <stdio.h>
#include <algorithm>
#include <vector>
#include <bitset>

using namespace std;

int main(){
    vector<int> prince(2), princess(3);
    while(scanf("%d%d%d%d%d", &princess[0], &princess[1], &princess[2], &prince[0], &prince[1]), princess[0]){
        sort(princess.begin(), princess.end());
        sort(prince.begin(), prince.end());
        bitset<53> used;
        int i;
        bool cont = true;
        used.set(prince[0]);
        used.set(prince[1]);
        used.set(princess[0]);
        used.set(princess[1]);
        used.set(princess[2]);
        if(prince[1] > princess[0]){
            if(prince[0]  < princess[2]){
                for(i = 0; i < prince[0]; ++i){
                    if(i > princess[1] && !used[i]){
                        printf("%d\n", i);
                        cont = false;
                        break;
                    }
                }
                if(cont){
                    if(prince[0] < princess[1]){
                        for(++i; i < prince[1]; ++i){
                            if(i > princess[2] && !used[i]){
                                printf("%d\n", i);
                                cont = false;
                                break;
                            }
                        }
                        if(cont){
                                if(prince[1] > princess[2]){
                                for(++i; i < 53; ++i){
                                    if(i > princess[0] && !used[i]){
                                        printf("%d\n", i);
                                        cont = false;
                                        break;
                                    }
                                }
                                if(cont){
                                    printf("-1\n");
                                }
                            }else{
                                printf("-1\n");
                            }
                        }
                    }else{
                        for(++i; used[i]; ++i);
                        if(i != 53)
                            printf("%d\n", i);
                        else
                            printf("-1\n");
                    }
                }
            }else{
                for(i = 1; used[i]; ++i);
                printf("%d\n", i);
            }
        }else{
            printf("-1\n");
        }
    }
}
