// http://usaco.org/index.php?page=viewproblem2&cpid=963&lang=en

#include<bits/stdc++.h>
using namespace std;

map<pair<int, int>, int> counters;
int K, N;

int main(void){
    freopen("gymnastics.in", "r", stdin);
    freopen("gymnastics.out", "w", stdout);
    cin >> K >> N;
    // set the data set first
    int currData[30] = {0};
    for (int i = 0; i < K; i++) {
        // input
        for (int k = 0; k < N; k++) {
            cin >> currData[k];
        }
        // modify counter, if not exists then create a new one
        for (int j = 0; j < N - 1; j++) {
            for (int k = j+1; k < N; k++) {
                pair<int, int> currPair = {currData[j], currData[k]};
                if (counters.find(currPair) != counters.end()) {
                    counters[currPair] += 1;
                }
                else {
                    counters[currPair] = 1;
                }
            }
        }
    }

    // iterate the map to check 
    int counter = 0;
    for (auto i = counters.begin(); i != counters.end(); i++) {
        // cout << i->second << endl;
        if (i->second == K) {
            counter++;
        }
    }
    cout << counter << endl;
    return 0;
}