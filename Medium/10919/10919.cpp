#include <cstring>
#include <iostream>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    bool yes, arr[10000];
    int k, m, c, r, temp;
    string ignore;
    while(cin >> k, k){
        memset(arr, 0, sizeof arr);
        yes = true;
        cin >> m;
        for(int i = 0; i < k; i++){
            cin >> temp;
            arr[temp] = true;
        }
        while(m--){
            cin >> c >> r;
            if(!r){
                cin.ignore();
                getline(cin, ignore);
                continue;
            }
            while(c--){
                cin >> temp;
                if(arr[temp]){
                    if(!--r){
                        if(c){
                            cin.ignore();
                            getline(cin, ignore);
                        }
                        break;
                    }
                }
            }
            if(r){
                yes = false;
                while(m--){
                    cin.ignore();
                    getline(cin, ignore);
                }
                break;
            }
        }
        if(yes)
            cout << "yes\n";
        else
            cout << "no\n";
    }
}
