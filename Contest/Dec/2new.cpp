#include<bits/stdc++.h>
using namespace std;

int main(void){
    int N;
    cin >> N;
    string patt;
    cin >> patt;

    int counter = 1;
    for (int i = 0; i < N - 2; i++) {
        for (int j = i; j <= i + 2; j++) {
            // cout << j << endl;
            if (patt[j] == '0') {
                counter++;
                break;
            }
            
        }
    }

    cout << counter << endl;
    return 0;
}