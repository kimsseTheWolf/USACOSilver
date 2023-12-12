#include<bits/stdc++.h>
using namespace std;

int C[3] = {0};
int M[3] = {0};


int main(void){
    freopen("mixmilk.in", "r", stdin);
    freopen("mixmilk.out", "w", stdout);
    for (int i = 0; i < 3; i++) {
        cin >> C[i] >> M[i];
    }
    for (int i = 0; i < 100; i++) {
        if (C[(i+1)%3] - M[(i+1)%3] >= M[i % 3]) {
            // means enough space in the next bucket. fill all
            M[(i+1)%3] += M[i % 3];
            M[i % 3] = 0;
        }
        else {
            int allowDiff = C[(i+1)%3] - M[(i+1)%3];
            M[(i+1)%3] += allowDiff;
            M[i % 3] -= allowDiff;
        }
    }
    for (int i = 0; i < 3; i++) {
        cout << M[i] << endl;
    }
    return 0;
}