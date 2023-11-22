// https://cses.fi/problemset/task/1629

#include<bits/stdc++.h>
using namespace std;

struct range{
    int start;
    int end;
};

bool comp (range a, range b) {
    return a.end < b.end;
}

range ranges[1000002];
int n;

int main(void){
    cin >> n;
    for (int i = 0; i < n; i++) {
        cin >> ranges[i].start >> ranges[i].end;
    }
    sort(ranges, ranges+n, comp);
    long long counter = 0, lastEnd = 0;
    for (int i = 0; i < n; i++) {
        if (ranges[i].start >= lastEnd) {
            // override
            counter++;
            lastEnd = ranges[i].end;
        }
    }
    cout << counter << endl;
    return 0;
}