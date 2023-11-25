// http://www.usaco.org/index.php?page=viewproblem2&cpid=571%EF%BC%88%E5%8F%8C%E6%8C%87%E9%92%88%E6%96%B9%E6%B3%95%E5%9C%A8%E5%8F%8C%E5%BA%8F%E5%88%97%E4%B8%AD%E7%9A%84%E5%BA%94%E7%94%A8%EF%BC%89

#include<bits/stdc++.h>
using namespace std;

int B[50002];
int E[50002];
int S[100001];
int N;

int main(void){
    freopen("highcard.in", "r", stdin);
    freopen("highcard.out", "w", stdout);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> E[i];
        S[E[i]] = 1;
    }
    for (int i = 1,j=0; i <= 2*N; i++) {
        if(S[i] == 0){
            B[j++] = i;
        }
    }
    sort(B,B+N);
    sort(E,E+N);
    int pb = 0, pe = 0, c = 0;
    while (pb < N && pe < N) {
        if (B[pb] > E[pe]) {
            pb++;
            pe++;
            c++;
        }
        else {
            pb++;
        }
    }
    cout << c;
    return 0;
}