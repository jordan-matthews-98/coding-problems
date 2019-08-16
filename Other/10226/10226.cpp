#include <iostream>
#include <unordered_map>
#include <set>

using namespace std;

int main(){
    ios::sync_with_stdio(false);
    unordered_map<string, int> trees;
    set<string> treeTypes;
    int t, counter;
    string tree;
    cin >> t;
    cin.ignore();
    getline(cin, tree);
    while(t--){
        trees.clear();
        treeTypes.clear();
        counter = 0;
        while(getline(cin, tree) && !tree.empty()){
            ++counter;
            ++trees[tree];
        }

        for(unordered_map<string, int>::iterator it = trees.begin(); it != trees.end(); ++it)
            treeTypes.insert(it->first);
        for(set<string>::iterator it = treeTypes.begin(); it != treeTypes.end(); ++it)
            printf("%s %.4f\n", (*it).c_str(), 100.0*trees[(*it)]/counter);
        if(t)
            printf("\n");
    }
}
