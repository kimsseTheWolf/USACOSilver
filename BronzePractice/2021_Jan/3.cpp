#include<bits/stdc++.h>
using namespace std;

int sizes[30];
int cows[30];
int flags[30] = {0};
int N;

int main(void){
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> cows[i];
    }
    for (int i = 0; i < N; i++) {
        cin >> sizes[i];
    }

    sort(cows, cows + N, greater<int>());
    sort(sizes, sizes + N, greater<int>());
    vector<int> possibilities;
    int lastPoss = 0;
    long long result = 1;
    for (int i = 0; i < N; i++) {
        int counter = 0;
        for (int j = 0; j < N; j++) {
            if (cows[i] <= sizes[j] && flags[j] == 0) {
                counter++;
            }
        }
        // mark up
        for (int j = 0; j < N; j++) {
            if (flags[j] == 1) {
                continue;
            }
            else {
                flags[j] = 1;
                break;
            }
        }
        result *= counter;
    }
    cout << result << endl;
    return 0;
}