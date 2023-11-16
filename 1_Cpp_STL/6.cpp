// https://cses.fi/problemset/task/1091

#include<bits/stdc++.h>
using namespace std;

int n, m;
multiset<int> h;

int main(void){
    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        int price;
        cin >> price;
        h.insert(price);
    }

    for (int i = 0; i < m; i++) {
        int price;
        cin >> price;
        if (h.size() == 0) {
            cout << -1 << endl;
            continue;
        }
        auto itr = h.lower_bound(price);
        if (itr == h.end()) {
            itr--;
            cout << *itr << endl;
            h.erase(itr);
        }
        else if (*itr == price) {
            cout << *itr << endl;
            h.erase(itr);
        }
        else if (itr == h.begin()) {
            cout << -1 << endl;
        }
        else {
            itr--;
            cout << *itr << endl;
            h.erase(itr);
        }
    }
    return 0;
}