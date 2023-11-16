// https://cses.fi/problemset/task/1084

#include<bits/stdc++.h>
using namespace std;

int n, m, k;
int a[200010];
multiset<int> b;
int ans;
int main(void) {
    cin >> n >> m >> k;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < m; i++) {
        int x;
        cin >> x;
        b.insert(x);
    }

    sort(a, a+n);
    for (int i = 0; i < n; i++) {
        auto itr = b.lower_bound(a[i] - k);
        if (itr != b.end()) {
            if (*itr <= a[i] + k) {
                ans++;
                b.erase(itr);
            }
        }
    }

    cout << ans << endl;
    return 0;
}