#include<bits/stdc++.h>
using namespace std;

int sums[100010];
int brokes[100010];
int N, K, B;

int main(void){
    freopen("maxcross.in", "r", stdin);
    freopen("maxcross.out", "w", stdout);
    cin >> N >> K >> B;
    for (int i = 0; i < B; i++) {
        cin >> brokes[i];
    }
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        if (find(brokes, brokes+B, i) != brokes+B) {
            sum++;
        }
        sums[i] = sum;
    }
    int ans = 1e9;
    for (int i = 1; i <= N - K + 1; i++) {
        ans = min(ans, sums[i+K-1] - sums[i-1]);
    }
    cout << ans << endl;

    return 0;
}