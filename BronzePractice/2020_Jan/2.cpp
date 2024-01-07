#include<bits/stdc++.h>
using namespace std;

int N;
vector<int> b;

int main(void){
    freopen("photo.in", "r", stdin);
    freopen("photo.out", "w", stdout);
    cin >> N;
    for (int i = 0; i < N - 1; i++) {
        int num;
        cin >> num;
        b.push_back(num);
    }

    vector<int> results;
    // apply the first two num
    results.push_back(b[0] - 1);
    results.push_back(1);
    for (int i = 1; i < b.size(); i++) {
        results.push_back(b[i] - results[i]);
    } 
    for (int i = 0; i < results.size(); i++) {
        cout << results[i];
        if (i != results.size() - 1) {
            cout << " ";
        }
    }
    return 0;
}