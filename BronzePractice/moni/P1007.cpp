#include<bits/stdc++.h>
using namespace std;

pair<int, bool> peoples[5010];
int L, N;

int main(void){
    cin >> L;
    cin >> N;

    if (N == 0) {
        cout << 0 << " " << 0 << endl;
        return 0;
    }
    for (int i = 0; i < N; i++) {
        int loc;
        cin >> loc;
        peoples[i] = {loc, false};
    }

    int minT = -1e9, maxT = -1e9;
    for (int i = 0; i < N; i++) {
        minT = max(minT, min(peoples[i].first, L+1-peoples[i].first));
        maxT = max(maxT, max(peoples[i].first, L + 1 - peoples[i].first));
    }

    cout << minT << " " << maxT << endl;
    return 0;
}