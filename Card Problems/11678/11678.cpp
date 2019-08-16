#include <stdio.h>
#include <algorithm>
#include <bitset>

using namespace std;

int main(){
    int A, B, n;
    while(scanf("%d%d", &A, &B), A){
        bitset<100001> a, b, s;
        while(A--){
            scanf("%d", &n);
            a.set(n);
        }
        while(B--){
            scanf("%d", &n);
            b.set(n);
        }
        s = a & b;
        a ^= s;
        b ^= s;
        printf("%d\n", min(a.count(), b.count()));
    }
}
