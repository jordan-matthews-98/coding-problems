#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main(){
    int n, caseNo = 0;

    while(scanf("%d", &n), n){
        vector<int> v(n);
        int num, m;

        for(int i = 0; i < n; ++i){
            scanf("%d", &num);
            v[i] = num;
        }
        sort(v.begin(), v.end());

        printf("Case %d:\n", ++caseNo);
        scanf("%d", &m);
        for(int i = 0; i < m; ++i){
            int target, lo = 0, hi = n - 1, closest = v[lo] + v[hi];
            scanf("%d", &target);
            if(closest > target)
                --hi;
            else
                ++lo;
            while(lo < hi && closest != target){
                if(abs(target - v[hi] - v[lo]) < abs(target - closest))
                    closest = v[hi] + v[lo];
                if(v[hi] + v[lo] > target)
                    --hi;
                else
                    ++lo;
            }
            printf("Closest sum to %d is %d.\n", target, closest);
        }
    }
}
