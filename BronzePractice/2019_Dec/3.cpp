// http://usaco.org/index.php?page=viewproblem2&cpid=965

#include<bits/stdc++.h>
using namespace std;

map<string, int> counters;
vector<pair<string, string>> reqs;
vector<vector<string>> notProcessed;
set<string> seq;
int N;

int main(void)
{
    cin >> N;
    // initialize counters
    counters["Bessie"] = 0;
    counters["Buttercup"] = 0;
    counters["Belinda"] = 0;
    counters["Beatrice"] = 0;
    counters["Bella"] = 0;
    counters["Blue"] = 0;
    counters["Betsy"] = 0;
    counters["Sue"] = 0;

    // apply to rules 
    for (int i = 0; i < N; i++) {
        string a, b, t1, t2, t3, t4;
        cin >> a >> t1 >> t2 >> t3 >> t4 >> b;
        reqs.push_back({a, b});
        counters[a]++;
        counters[b]++;
    }
    return 0;
}