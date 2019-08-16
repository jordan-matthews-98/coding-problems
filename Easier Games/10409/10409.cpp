#include <stdio.h>

int main(){
    int n;
    while(scanf("%d", &n), n){
        char command[6];
        int temp, top = 1, bottom = 6, left = 3, right = 4, front = 2, back = 5;
        while(n--){
            getchar();
            scanf("%s", command);
            switch(command[0]){
                case 'n':
                    temp = top;
                    top = back;
                    back = bottom;
                    bottom = front;
                    front = temp;
                    break;
                case 's':
                    temp = top;
                    top = front;
                    front = bottom;
                    bottom = back;
                    back = temp;
                    break;
                case 'e':
                    temp = top;
                    top = left;
                    left = bottom;
                    bottom = right;
                    right = temp;
                    break;
                case 'w':
                    temp = top;
                    top = right;
                    right = bottom;
                    bottom = left;
                    left = temp;
                    break;
            }
        }
        printf("%d\n", top);
    }
}
