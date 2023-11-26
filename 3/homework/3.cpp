// https://cses.fi/problemset/task/1619

#include<bits/stdc++.h>
using namespace std;

map<int, int> arecords;

int n;

int main(void) {
    cin >> n;
    int end = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        arecords[a] = 1;
        arecords[b] = -1;
        end = max(end, b);
    }
    int count = 0, maxCount = 0;
    for (int i = 0; i < end; i++) {
        count += arecords[i];
        maxCount = max(maxCount, count);
    }
    cout << maxCount;
    return 0;
}