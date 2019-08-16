#include <stdio.h>
#include <cmath>

using namespace std;

int main(){
    int mainHeight, numWorkers;
    while(scanf("%d %d", &mainHeight, &numWorkers), mainHeight){
        if(mainHeight == 1){
            printf("0 1\n");
        }else{
            double root, e = 1e-7;
            int power = 0;
            do{
                root = pow(mainHeight, 1.0/++power);
            }while(abs(root - pow(numWorkers, 1.0/power) - 1) > e);
            if(root == 2){
                printf("%d %d\n", power, mainHeight*2-numWorkers);
            }else{
                printf("%.0f %.0f\n", (numWorkers - 1)/(root - 2), mainHeight*root-numWorkers*(root-1));
            }
        }
    }
}
