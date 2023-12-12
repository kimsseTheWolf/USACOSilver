#include<bits/stdc++.h>
using namespace std;

struct restStop{
    int distance;
    int flavor;
};

int L, N, rF, rB;
restStop stops[10010];

int main(void){
    cin >> L >> N >> rF >> rB;
    for (int i = 0; i < N; i++) {
        cin >> stops[i].distance >> stops[i].flavor;
    }
    int counter = 0;
    for (int i = 0; i < N; i++) {
        // see how long Bessie will take to get to the stop
        // apply the time to fj's speed to see when will 
    }
    return 0;
}