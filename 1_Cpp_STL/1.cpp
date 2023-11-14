// https://www.luogu.com.cn/problem/P1678

#include<iostream>
#include<vector>
#include<set>
#include<cmath>
#include<stdio.h>

using namespace std;

set<int> collegeScores = {};
int stdScoeres[1000000] = {};

int main()
{
    freopen("P1678_5.in", "r", stdin);
    // freopen("test.out", "w", stdout);
    int schoolNum = 0, studentNum = 0;
    cin >> schoolNum >> studentNum;
    // Enter school scores
    for (int i = 0; i < schoolNum; i++) {
        int schoolAcceptScore = 0;
        cin >> schoolAcceptScore;
        collegeScores.insert(schoolAcceptScore);
    }

    cout << "Insertion finished" << endl;
    // add the min and max to speed up the calculation
    int minScore = *collegeScores.begin(), maxScore = *(--collegeScores.end());

    // calculate the sum
    long long sum = 0;
    for (int i = 0; i < studentNum; i++) {
        int currentScore;
        cin >> currentScore;
        // the one above the score
        int upperScore = *lower_bound(collegeScores.begin(), collegeScores.end(), currentScore);
        int lowerScore = *(--lower_bound(collegeScores.begin(), collegeScores.end(), currentScore));
        sum += min(abs(currentScore - upperScore), abs(currentScore - lowerScore));
        // cout << i << endl;
    }

    cout << sum << endl;
    return 0;
}