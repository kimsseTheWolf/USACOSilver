// https://www.luogu.com.cn/problem/P4447

#include<bits/stdc++.h>
using namespace std;

int a[100010];
int n;
vector<int> e, l;
int g[100010];
int c[100010];
int num = 0;

int main(void){
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    sort(a, a+n);
    g[num] = a[0] + 1;
    c[num] = 1;
    num++;
    for (int i = 1; i < n; i++) {
        int p = lower_bound(g, g+num, a[i]) - g;
        // cout << a[i] << ", " << p << endl;
        if (p >= num || g[p] != a[i]) {
            g[num] = a[i] + 1;
            c[num] = 1;
            num++;
        }
        else {
            while (g[p] == a[i]) {
                p++;
            }
            p--;
            g[p] = a[i]+1;
            c[p]++;
        }
    }
    int ans = INT_MAX;
    for (int i = 0; i < num; i++) {
        ans = min(ans, c[i]);
    }
    cout << ans << endl;
    
    return 0;
}