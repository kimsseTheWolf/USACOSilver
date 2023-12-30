// www.usaco.org/index.php?page=viewproblem2&cpid=572

#include<bits/stdc++.h>
using namespace std;

int a[100010];
int b[100010];
int c[100010];
int sum;
int N, Q;
int sa = 0, sb = 0, sc = 0;

int main(void){
    freopen("bcount.in", "r", stdin);
    freopen("bcount.out", "w", stdout);
    cin >> N >> Q;
    for (int i = 1; i <= N; i++) {
        cin >> sum;
        // if (sum[i] == 1) {
        //     sa++;
        // }
        // else if (sum[i] == 2) {
        //     sb++;
        // }
        // else {
        //     sc++;
        // }
        // // apply prefix
        // a[i] = sa;
        // b[i] = sb;
        // c[i] = sc;
        a[i] = a[i - 1] + (sum == 1);
        b[i] = b[i - 1] + (sum == 2);
        c[i] = c[i - 1] + (sum == 3);
    }

    for (int i = 0; i < Q; i++) {
        int begin, end;
        cin >> begin >> end;
        cout << a[end] - a[begin - 1] << " " << b[end] - b[begin - 1] << " " << c[end] - c[begin - 1] <<endl;
    }

    return 0;
}