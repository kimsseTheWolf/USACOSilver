#include<bits/stdc++.h>
using namespace std;

int N;
int b[100010];
int g[100010];
unordered_map<int, int> records;

int main(void){
    ios::sync_with_stdio(false);
    cin >> N;
    int bSum = 0, gSum = 0;
    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        num == 0 ? gSum++ : bSum++;
        b[i] = bSum;
        g[i] = gSum;
        // cout << b[i] << g[i] << endl;
    }

    int length = 0;
    records[0] = 0;
    for (int i = 1; i <= N; i++) {
        if (records.count(b[i] - g[i])) {
            length = max(length, i - records[b[i] - g[i]]);
        }
        else {
            records[b[i] - g[i]] = i;
        }
    }
    cout << length << endl;
    return 0;
}