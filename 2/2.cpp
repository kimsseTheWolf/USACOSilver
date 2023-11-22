// https://www.luogu.com.cn/problem/P2240
// https://www.luogu.com.cn/record/136422662

#include<bits/stdc++.h>
using namespace std;

struct coinPile {
    int value;
    int weight;
    double singleValue;
};

bool comp(coinPile a, coinPile b) {
    return a.singleValue >= b.singleValue;
}

int N, T;
coinPile piles[102];

int main(void){
    cin >> N >> T;
    for (int i = 0; i < N; i++) {
        cin >> piles[i].weight >> piles[i].value;
        piles[i].singleValue = (double)piles[i].value / piles[i].weight;
    }

    sort(piles, piles + N, comp);

    int weightCounter = 0;
    double totalValue = 0;
    for (int i = 0; i < N; i++){
        if (weightCounter + piles[i].weight < T) {
            // Add all
            weightCounter += piles[i].weight;
            totalValue += piles[i].value;
        }
        else {
            // Add the left space
            totalValue += (T - weightCounter) * piles[i].singleValue;
            break;
        }
    }
    cout << fixed << setprecision(2) << totalValue << endl;
    return 0;
}