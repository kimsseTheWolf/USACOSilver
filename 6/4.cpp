#include<bits/stdc++.h>
using namespace std;

int nums[200010];
int N, sum;


int main(void){
    cin >> N >> sum;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    int lpt = 0, rpt = 0, counter = 0, ts = 0;
    while (lpt < N and rpt < N) {
        // if (ts < sum){
        //     ts = ts - nums[rpt-1] + nums[rpt];
        //     rpt++;
        // }
        // else if (ts > sum){
        //     lpt++;
        //     ts = ts - nums[lpt - 1] + nums[lpt];
        // }
        // else {
        //     counter++;
        //     rpt++;
        // }
        ts += nums[rpt];
        while (ts > sum) {
            ts -= nums[lpt];
            lpt++;
        }
        if (ts == sum) {
            counter++;
        }
        rpt++;
    }
    cout << counter << endl;
    return 0;
}