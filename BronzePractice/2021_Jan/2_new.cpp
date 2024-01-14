#include<bits/stdc++.h>
using namespace std;

int cows[1010];
int N;
int evenNum;
int oddNum;

int main(void){
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> cows[i];
        if (cows[i] % 2 == 0) {
            evenNum++;
        }
        else {
            oddNum++;
        }
    }

    while (oddNum > evenNum) {
        oddNum += 1;
        evenNum -= 2;
    }
    if (evenNum > oddNum) {
        evenNum = oddNum + 1;
    }
    cout << evenNum + oddNum << endl;

    return 0;
}