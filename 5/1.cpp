#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> records, staticRecords;
int N = 0;

int main(void){
    cin >> N;
    for (int i = 0; i < N; i++) {
        int a, b;
        cin >> a >> b;
        records.push_back({a, 1});
        records.push_back({b, -1});
    }
    sort(records.begin(), records.end());
    staticRecords = records;
    // delete every of them
    int maxTime = 0;
    auto it = staticRecords.begin();
    for (int i = 0; i < N; i++) {
        cout << "it: " << it->first << endl;
        records.erase(it);
        // iterate to see the total amount of time
        int currAm = 1, totalH = 0, lastValidH = 1;
        for (int j = 0; j < records.size() * 2; j++) {
            currAm += records[j].second;
            if (records[j].second == 1) {
                if (currAm == 1) {
                    // change from zero
                    lastValidH = records[j].first;
                }
                else {
                    // other situation
                    continue;
                }
            }
        }

        // override and reset
        maxTime = max(maxTime, totalH);
        records = staticRecords;
        it++;
    }
    cout << maxTime << endl;
    return 0;
}