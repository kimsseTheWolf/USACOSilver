// http://usaco.org/index.php?page=viewproblem2&cpid=714

#include<bits/stdc++.h>
using namespace std;

multiset<int> Chicken;
pair<int, int> Cow[20010];
int C, N;

int main(void){
    freopen("helpcross.in", "r", stdin);
    freopen("helpcross.out", "w", stdout);
    cin >> C >> N;
    for (int i = 0; i < C; i++) {
        int input;
        cin >> input;
        Chicken.insert(input);
    }
    for (int i = 0; i < N; i++) {
        cin >> Cow[i].second >> Cow[i].first;
    }
    sort(Cow, Cow+N);

    int ans = 0;
    for (int i = 0; i < N; i++) {
        auto itr = Chicken.lower_bound(Cow[i].second);
        if(itr != Chicken.end() and *itr <= Cow[i].first){
            ans++;
            Chicken.erase(itr);
        }
        //if (Chicken.lower_bound(Cow[i].first) == Chicken.begin() && *Chicken.lower_bound(Cow[i].first) != Cow[i].first) {
        //    continue;
        //}
        //if (Chicken.lower_bound(Cow[i].second) != Chicken.end() && *Chicken.lower_bound(Cow[i].second) <= *Chicken.lower_bound(Cow[i].first))
        //{
        //    Chicken.erase(Chicken.lower_bound(Cow[i].second));
        //    counter++;
        //}
    }
    cout << ans << endl;
    return 0;
}