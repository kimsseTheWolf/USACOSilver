#include<bits/stdc++.h>
using namespace std;


int N;
int main(void){
    // input
    cin >> N;
    vector<int> pattern;
    int count = 0;
    for (int i = 0; i < N; i++) {
        cin >> pattern[i];
        if (pattern[i] == 1) {
            count++;
        }
    }

    // simulate
    cout << count << endl;
    return 0;
}