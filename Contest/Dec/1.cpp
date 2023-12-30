#include<bits/stdc++.h>
using namespace std;

int N, M;
long long cows[1000010];
long long candies[1000010];

int main(void){
    cin >> N >> M;
    for (int i = 0; i < N; i++) {
        cin >> cows[i];
    }
    for (int i = 0; i < M; i++) {
        cin >> candies[i];
    }

    // feed each candies
    int cowPt = 0, candyPt = 0, groundHeight = 0;
    while (candyPt < M) {
        if (cows[cowPt%N] >= candies[candyPt] && groundHeight < candies[candyPt]) {
            // eat all of them
            cows[cowPt % N] += candies[candyPt];
            groundHeight = candies[candyPt];
        }
        else {
            if (groundHeight < candies[candyPt]) {
                if (cows[cowPt%N] >= groundHeight) {
                    long long diff = abs(groundHeight - cows[cowPt % N]);
                    cows[cowPt % N] += diff;
                    groundHeight += diff;
                }
            }
        }
        cowPt++;
        if (cowPt != 0 && cowPt % N == 0)
        {
            candyPt++;
            groundHeight = 0;
        }
    }

    for (int pt = 0; pt < N; pt++) {
        cout << cows[pt] << endl;
    }
    return 0;
}