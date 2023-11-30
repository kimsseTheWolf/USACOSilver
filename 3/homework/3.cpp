// https://cses.fi/problemset/task/1619

#include<bits/stdc++.h>
using namespace std;

map<int, int> arecords;
vector<pair<int, int>> record;

int n;

int main(void) {
    cin >> n;
    int end = 0;
    for (int i = 0; i < n; i++) {
        int a, b;
        cin >> a >> b;
        record.push_back({a, 1});
        record.push_back({b, -1});
    }
    sort(record.begin(), record.end());
    int count = 0, maxCount = 0;
    for (int i = 0; i < record.size(); i++) {
        count += record[i].second;
        maxCount = max(maxCount, count);
    }
    cout << maxCount;
    return 0;
}