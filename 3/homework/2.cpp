// http://www.usaco.org/index.php?page=viewproblem2&cpid=787

#include<bits/stdc++.h>
using namespace std;

int cows[100010] ;
pair<int, int> cowsInfo[100010];
pair<int, int> stores[100010];
int neightbors[100010];
int N, M, R;
int storeprofit[100010];
int rentprofit[100010];

bool comp(pair<int, int> a, pair<int, int> b) {
    return a.second > b.second;
}

int main(void){
    freopen("rental.in", "r", stdin);
    freopen("rental.out", "w", stdout);
    cin >> N >> M >> R;
    for (int i = 0; i < N; i++) {
        cin >> cows[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> stores[i].first >> stores[i].second;
    }
    for (int i = 0; i < R; i++) {
        cin >> neightbors[i];
    }

    sort(cows, cows+N, greater<int>());
    sort(stores, stores+M, comp);
    sort(neightbors, neightbors+R,greater<int>());

    // calc the store items first
    int cowpt = 0, storept = 0;
    while (cowpt < N && storept < M) {
        if (stores[storept].first >= cows[cowpt]) {
            stores[storept].first -= cows[cowpt];
            //cowsInfo[cowpt].first += cows[cowpt] * stores[storept].second;
            storeprofit[cowpt] += cows[cowpt] * stores[storept].second;
            cows[cowpt] = 0;
            cowpt++;
        }
        else {
            storeprofit[cowpt] += stores[storept].first * stores[storept].second;
            cows[cowpt] -= stores[storept].first;
            stores[storept].first = 0;
            storept++;
        }
    }

    int i = N-1, j = 0;
    while(i >= 0 and j < N){
        rentprofit[i] = neightbors[j];
        i--;
        j++;
    }

    long long sum = 0;
    // calc the borrowing second
    for (int i = 0; i < N; i++) {
        // cout << cowsInfo[i].first << " " << neightbors[i] << endl;
        sum += max(storeprofit[i], rentprofit[i]);
    }
    cout << sum << endl;
    return 0;
}