// https://www.luogu.com.cn/problem/P1678
// Not using vector

#include<iostream>
#include<algorithm>
#include<stdio.h>
using namespace std;

int main () {
    // process school scores
    int schoolNum = 0, stuNum = 0, schoolScores[100002];
    cin >> schoolNum >> stuNum;
    for (int i = 0; i < schoolNum; i++) {
        cin >> schoolScores[i];
    }
    sort(schoolScores, schoolScores + schoolNum);

    // process student scores
    long long sum = 0;
    for (int i = 0; i < stuNum; i++) {
        int currentScore = 0;
        cin >> currentScore;
        // special treatment
        if (currentScore < schoolScores[0]) {
            sum += schoolScores[0] - currentScore;
            continue;
        }
        else if (currentScore > schoolScores[schoolNum - 1]) {
            sum += currentScore - schoolScores[schoolNum - 1];
            continue;
        }

        // otherwise calculate the differences
        int upper = lower_bound(schoolScores, schoolScores + schoolNum, currentScore) - schoolScores;
        int lower = upper - 1;
        sum += min(abs(schoolScores[upper] - currentScore), abs(schoolScores[lower] - currentScore));
    }

    cout << sum << endl;
    return 0;
}