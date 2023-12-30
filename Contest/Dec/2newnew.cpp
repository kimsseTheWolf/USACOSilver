#include<bits/stdc++.h>
using namespace std;

string patt;

int main(void){
    int N;
    cin >> N;
    cin >> patt;
    vector<bool> isActive(N, false);
    int counter = 1;
    for (int i = 0; i < patt.size(); i++) {
        if (i == 0) {
            if (patt[i] == '0' && patt[i+1] == '1') {
                isActive[i+1] = true;
            }
        }
        else if (i == N -1) {
            if (patt[i] == '1' && patt[i-1] == '0') {
                isActive[i] = true;
            }
        }
        else {
            if (patt[i] == '1' && (isActive[i - 1] == true && isActive[i + 1] == true)) {
                isActive[i] = true;
            }
            else if (patt[i] == '1' && (patt[i - 1] == '0' || patt[i + 1] == '0')) {
                isActive[i] = true;
            }
            else if (patt[i] == '0') {
                if (patt[i-1] == '1') {
                    isActive[i-1] = true;
                }
                if (patt[i + 1] == '1'){
                    isActive[i + 1] = true;
                }
            }
        }
    }
    for (int i = 0; i < isActive.size(); i++) {
        if (isActive[i]) {
            counter++;
        }
    }
    cout << counter << endl;
    return 0;
}