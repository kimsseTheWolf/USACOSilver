#include<bits/stdc++.h>
using namespace std;

long long L, N, rF, rB;
long long x[100010], c[100010];

int main(void){
    freopen("reststops.in", "r", stdin);
    freopen("reststops.out", "w", stdout);
    cin >> L >> N >> rF >> rB;
    for (int i = 0; i < N; i++){
        cin >> x[i] >> c[i];
    }

    long long ans = c[N-1]*x[N-1]*(rF - rB), lastC = c[N-1];
    for (int i = N - 2; i >= 0; i--) {
        if (c[i] > lastC) {
            ans += x[i] * (c[i] - lastC) * (rF-rB);
            lastC = c[i];
        }
    }

    cout << ans << endl;
    
    return 0;
}