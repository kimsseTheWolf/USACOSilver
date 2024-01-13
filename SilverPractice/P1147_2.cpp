#include<bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, int>> results;
int sums[2000010];

int main(void){
    cin >> N;
    // calculate the prefix sum
    for(int i = 1; i <= N; i++){
        sums[i] = sums[i - 1] + i;
    }
    // cout << "sums[N]: " << sums[N] << endl;

    int lpt = 1, rpt = 2;
    while(lpt < rpt){
        int sum = sums[rpt] - sums[lpt - 1];
        // cout << "sum: " << sum << endl;
        // cout << "L: " << lpt << " R: " << rpt << endl;
        if(sum == N){
            results.push_back(make_pair(lpt, rpt));
            rpt++;
        }
        else if(sum < N){
            rpt++;
        }
        else{
            lpt++;
        }
    }

    sort(results.begin(), results.end());
    for(int i = 0; i < results.size(); i++){
        cout << results[i].first << " " << results[i].second << endl;
    }
    return 0;
}