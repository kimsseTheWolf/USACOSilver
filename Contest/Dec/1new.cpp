#include<bits/stdc++.h>
using namespace std;

long long candies[1000010];
long long cows[10000010];
int N, M;

int main(void){
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> cows[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> candies[i];
    }

    int groundHeight = 0;
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            if (candies[i] - groundHeight <= 0) {
                continue;
            }
            if (cows[j] >= candies[i]) {
                // eat all
                cows[j] += candies[i] - groundHeight;
                groundHeight = candies[i];
            }
            else {
                if (cows[j] >= groundHeight) {
                    int diff = cows[j] - groundHeight;
                    groundHeight += diff;
                    cows[j] += diff;
                }
                else {
                    // it got nothing
                    continue;
                }
            }
        }
        groundHeight = 0;
    }
    for (int i = 0; i < N; i++) {
        cout << cows[i] << endl;
    }
    return 0;
}