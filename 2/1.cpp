#include<bits/stdc++.h>
using namespace std;

int a[102] = {};
int X, N;

int main(void){
    cin >> N >> X;
    for (int i = 0; i < N; i++) {
        cin >> a[i];
    }

    sort (a, a + N);

    int sum = 0, i = 0, counter = 0;
    while (sum <= X && i < N) {
        sum += a[i];
        i++;
        counter++;
    }

    cout << counter - 1 << endl;
    
    return 0;
}