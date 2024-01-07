#include<bits/stdc++.h>
using namespace std;

vector<pair<int, int>> avaiPairs;
int M;

int main(void){
    cin >> M;
    int lpt = 0, rpt = 1, sum = 1;
    while (lpt < M / 2) {
        cout << lpt << " " << rpt << endl;
        if (sum > M) {
            sum -= lpt;
            lpt++;
        }
        else if (sum < M && rpt < M) {
            rpt++;
            sum += rpt;
        }
        else if (sum < M && rpt >= M) {
            sum -= lpt;
            lpt++;
        }
        else {
            avaiPairs.push_back({lpt, rpt});
            lpt++;
        }
    }
    sort(avaiPairs.begin(), avaiPairs.end());
    for (int i = 0; i < avaiPairs.size(); i++) {
        cout << avaiPairs[i].first << " " << avaiPairs[i].second << endl;
    }
    return 0;
}