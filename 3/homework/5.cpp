// http://www.usaco.org/index.php?page=viewproblem2&cpid=896

#include<bits/stdc++.h>
using namespace std;

struct mPoints{
    int start;
    int end;
    int x;
    int y;
};

bool comp(mPoints a, mPoints b) {
    return a.start < b.start;
}

mPoints mountains[100002];
int N, x, y;


int main(void){
    // freopen("mountains.in", "r", stdin);
    // freopen("mountains.out", "w", stdout);
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> x >> y;
        mountains[i].start = x - y;
        mountains[i].end = x + y;
        mountains[i].x = x;
        mountains[i].y = y;
    }
    sort(mountains, mountains+N, comp);
    int maxEnd = mountains[0].end - 1, count = 0;
    for (int i = 0; i < N; i++) {
        if (mountains[i].end > maxEnd)
        {
            count++;
            maxEnd = max(maxEnd, mountains[i].end);
        }
    }
    cout << count << endl;
    return 0;
}