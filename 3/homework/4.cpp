// http://www.usaco.org/index.php?page=viewproblem2&cpid=835

#include<bits/stdc++.h>
using namespace std;

int N;
int waitingNum[10002];

int main(void){
    freopen("lemonade.in", "r", stdin);
    freopen("lemonade.out", "w", stdout);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> waitingNum[i];
    }
    sort(waitingNum, waitingNum+N, greater<int>());

    int count = 0, maxCount = 0, queueNum = 0;
    for (int i = 0; i < N; i++) {
        if (queueNum <= waitingNum[i]) {
            // means okay. get into the line
            queueNum++;
            count++;
        }
        else {
            // means no longer wait
            maxCount = max(maxCount, count);
            queueNum = 1;
            count = 0;
        }
    }
    maxCount = max(maxCount, count);
    cout << maxCount;
    return 0;
}