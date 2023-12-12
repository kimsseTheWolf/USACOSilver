#include<bits/stdc++.h>
using namespace std;

struct timePoint {
    int time;
    bool isBorrow;
    int amount;
};
bool comp(timePoint a, timePoint b) {
    return a.time < b.time;
}

timePoint points[210];
int N;

int main(void){
    freopen("blist.in", "r", stdin);
    freopen("blist.out", "w", stdout);
    cin >> N;
    for (int i = 0; i < N * 2; i+=2) {
        int start, end, amount;
        cin >> start >> end >> amount;
        points[i].time = start;
        points[i].isBorrow = true;
        points[i].amount = amount;
        points[i+1].time = end;
        points[i+1].isBorrow = false;
        points[i+1].amount = amount;
    }
    sort(points, points + (N * 2), comp);
    int needBucket = 0, availableBucket = 0;
    for (int i = 0; i < N * 2; i++) {
        if (points[i].isBorrow) {
            if (points[i].amount <= availableBucket) {
                availableBucket -= points[i].amount;
                continue;
            }
            else {
                needBucket += points[i].amount - availableBucket;
                availableBucket = 0;
                continue;
            }
        }
        else {
            availableBucket += points[i].amount;
        }
    }
    cout << needBucket << endl;
    return 0;
}