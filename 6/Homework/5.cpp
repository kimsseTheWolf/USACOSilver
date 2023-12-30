// 两两组对保证所有的和最小：最小的元素+最大的元素！！

#include<bits/stdc++.h>
using namespace std;

int N;
pair<int, int> pairs[1000010];

int main(void){
    freopen("pairup.in", "r", stdin);
    freopen("pairup.out", "w", stdout);
    cin >> N;
    for (int i = 0; i < N; i++) {
        int cowNum, cowTime;
        cin >> cowNum >> cowTime;
        pairs[i] = {cowTime, cowNum};
    }
    sort(pairs, pairs+N);

    int lpt = 0, rpt = N - 1, minTime = -1e9;
    while (lpt <= rpt) {
        minTime = max(minTime, pairs[lpt].first + pairs[rpt].first);
        pairs[lpt].second--;
        pairs[rpt].second--;
        if (pairs[lpt].second <= 0) {
            lpt++;
        }
        if (pairs[rpt].second <= 0) {
            rpt--;
        }
    }
    cout << minTime << endl;
    return 0;
}