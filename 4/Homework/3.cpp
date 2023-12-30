#include <bits/stdc++.h>
using namespace std;

using ll = long long;

int main()
{
    freopen("fuel.in", "r", stdin);
    freopen("fuel.out", "w", stdout);

    vector<pair<int, int>> stations;
    int s[50000], next[50000];

    int n, maxGas, curr, dist;
    cin >> n >> maxGas >> curr >> dist;

    for (int i = 0; i < n; i++)
    {
        int pos, cost;
        cin >> pos >> cost;
        stations.push_back({pos, cost});
    }

    sort(stations.begin(), stations.end());

    int stk = 0;
    for (int i = n - 1; i >= 0; i--)
    {
        // while (stk > 0 && stations[s[stk - 1]].second >= stations[i].second)
        // {
        //     stk--;
        // }
        // next[i] = (stk == 0 ? -1 : s[stk - 1]);
        // s[stk] = i;
        // stk++;
        next[i] = -1;
        for (int j = i + 1; j < n; j++) {
            if (stations[j].second < stations[i].second) {
                next[i] = j;
                break;
            }
        }
    }

    curr -= stations[0].first;

    ll cost = 0;
    for (int i = 0; i < n; i++)
    {
        if (curr < 0)
        {
            printf("-1\n");
            return 0;
        }

        int need = min(maxGas, (next[i] == -1 ? dist : stations[next[i]].first) - stations[i].first);
        if (need > curr)
        {
            cost += (ll)(need - curr) * (ll)stations[i].second;
            curr = need;
        }

        curr -= (i == n - 1 ? dist : stations[i + 1].first) - stations[i].first;
    }

    if (curr < 0)
    {
        cout << "-1\n";
        return 0;
    }

    cout << cost << "\n";
}