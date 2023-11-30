// http://usaco.org/index.php?page=viewproblem2&cpid=381

#include<bits/stdc++.h>
using namespace std;

pair<int, int> tbl[200];
pair<int, int> cam1 = {-1, -1}, cam2 = {-1, -1};
int group1 = 0 ; //
int group2 = 0 ; //

int N, ans = 0;

int main(void){
    freopen("recording.in", "r", stdin);
    freopen("recording.out", "w", stdout);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> tbl[i].second >> tbl[i].first;
    }
    sort(tbl, tbl+N);

    for (int i = 0; i < N; i++) {
        if (tbl[i].second >= group1 and tbl[i].second >= group2) {
            if(group1 >= group2){
                group1 = tbl[i].first;
            }
            else{
                group2 = tbl[i].first;
            }
            ans++;
        }
        else {
            if (tbl[i].second >= group1){
                ans++;
                group1 = tbl[i].first;
            }
            else if(tbl[i].second >= group2) {
                ans++;
                group2 = tbl[i].first;
            }
        }
    }
    cout << ans << endl;
    return 0;
}