// https://cses.fi/problemset/task/1630

#include<bits/stdc++.h>
using namespace std;

struct task{
    long long duration;
    long long deadline;
};
bool comp(task a, task b) {
    return a.duration < b.duration;
}
task tasks[1000002];
int n = 0;

int main(void){
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> tasks[i].duration >> tasks[i].deadline;
    }
    sort(tasks, tasks+n, comp);
    long long currentTime = 0, pointCounter = 0;
    for (int i = 0; i < n; i++) {
        currentTime += tasks[i].duration;
        pointCounter += tasks[i].deadline - currentTime;
    }
    cout << pointCounter;
    return 0;
}