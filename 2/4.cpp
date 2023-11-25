// https://www.luogu.com.cn/problem/P1094

#include<bits/stdc++.h>
using namespace std;

int w, n;
int items[300002];

int main(void){
    cin >> w;
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> items[i];
    }

    sort(items, items+n);

    int upper = n - 1, lower = 0, counter = 0;
    while (upper >= lower) {
        if (items[lower] + items[upper] > w) {
            upper--;
        }
        else {
            upper--;
            lower++;
        }
        counter++;
    }
    cout << counter;
    return 0;
}