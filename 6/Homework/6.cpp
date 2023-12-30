#include<bits/stdc++.h>
using namespace std;

set<int> cities;
set<int> cells;
int n, m;

int main(void){

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        cities.insert(input);
    }
    for (int i = 0; i < m; i++) {
        int input;
        cin >> input;
        cells.insert(input);
    }
    int minDistance = -1e9;
    for (auto i = cities.begin(); i != cities.end(); i++) {
        auto lCell = cells.lower_bound(*i);
        auto rCell = cells.lower_bound(*i);
        if (*lCell != *i && lCell != cells.begin()) {
            lCell--;
        }
        if (rCell == cells.end()) {
            rCell--;
        }

        minDistance = max(minDistance, min(abs(*lCell - *i), abs(*rCell - *i)));
        // cout << "Left: " << *lCell << " Right: " << *rCell << " Distance: " << minDistance << endl;
    }
    cout << minDistance << endl;

    return 0;
}