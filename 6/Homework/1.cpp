#include<bits/stdc++.h>
using namespace std;

int N;
long long sums[50010];

int main(void){
    freopen("div7.in", "r", stdin);
    freopen("div7.out", "w", stdout);
    cin >> N;
    long long sum = 0;
    for (int i = 1; i <= N; i++) {
        int input;
        cin >> input;
        sum += input;
        sums[i] = sum;
    }
    long long ans = 0;
    for (long long i = 1; i <= N; i++) {
        for (long long j = i + 1; j <= N; j++) {
            if ((sums[j] - sums[i-1]) % 7 == 0) {
                ans = max(ans, j - i + 1);
            }
        }
    }
    cout << ans << endl;
    return 0;
}