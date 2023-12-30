// http://www.usaco.org/index.php?page=viewproblem2&cpid=691

#include<bits/stdc++.h>
using namespace std;

int h[100010];
int p[100010];
int s[100010];
int sh = 0, sp = 0, ss = 0;
int N;

int main(void){
    freopen("hps.in", "r", stdin);
    freopen("hps.out", "w", stdout);
    cin >> N;
    for (int i = 1; i <= N; i++) {
        char in;
        cin >> in;
        h[i] = h[i-1] + (in == 'H');
        s[i] = s[i - 1] + (in == 'S');
        p[i] = p[i - 1] + (in == 'P');
    }
    int mSum = 0;
    for (int i = 1; i <= N; i++) {
        int maxA = max(h[i], max(s[i], p[i]));
        int maxB = max(h[N] - h[i], max(s[N] - s[i], p[N] - p[i]));
        mSum = max(maxA+maxB, mSum);
    }
    cout << mSum << endl;
    return 0;
}