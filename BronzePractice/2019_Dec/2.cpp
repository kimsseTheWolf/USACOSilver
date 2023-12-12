// http://usaco.org/index.php?page=viewproblem2&cpid=964&lang=zh

#include<bits/stdc++.h>
using namespace std;

set<string> avaiPattern;
int N;
string content;

int main(void){
    freopen("whereami.in", "r", stdin);
    freopen("whereami.out", "w", stdout);
    cin >> N;
    cin >> content;
    int result = 0;
    for (int i = 1; i <= content.length(); i++) {
        bool isUnique = true;
        avaiPattern.clear();
        for (int j = 0; j < content.length() - i + 1; j++) {
            // cout << j << " " << j + i << content.substr(j, j + i) << endl;
            if (avaiPattern.find(content.substr(j, i)) != avaiPattern.end()) {
                // means not unique
                isUnique = false;
                break;
            }
            else {
                avaiPattern.insert(content.substr(j, i));
            }
        }
        if (isUnique) {
            cout << i << endl;
            return 0;
        }
    }
    return 0;
}