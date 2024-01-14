#include<bits/stdc++.h>
using namespace std;

int cows[1010];
int N;

int main(void){
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> cows[i];
    }
    int counter = 1, pt = 1;
    bool isEven = false, lastIsEven = (cows[0] % 2 == 0);
    while (pt < N) {
        isEven = (cows[pt] % 2 == 0);
        if (isEven != lastIsEven) {
            cout << "not the same" << endl;
            counter++;
            pt++;
            lastIsEven = isEven;
        }
        else {
            cout << "the same" << endl;
            int rpt = pt + 1;
            while (rpt < N) {
                if (((cows[pt] + cows[rpt]) % 2 == 0) != lastIsEven) {
                    counter++;
                    lastIsEven = !lastIsEven;
                    pt = rpt;
                    break;
                }
                else {
                    rpt++;
                }
            }
        }

    }

    cout << counter << endl;
    return 0;
}