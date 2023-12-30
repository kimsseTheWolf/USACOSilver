// https://cses.fi/problemset/task/1640/

#include<bits/stdc++.h>
using namespace std;

pair<int, int> nums[200010];
int N, sum;

int main(void){
    cin >> N >> sum;
    for (int i = 0; i < N; i++) {
        nums[i].second = i+1;
        cin >> nums[i].first;
    }
    sort(nums, nums+N);
    int lpt = 0, rpt = N-1;
    bool found = false;
    while (lpt < rpt) {
        int tsum = nums[lpt].first + nums[rpt].first;
        if (tsum < sum) {
            lpt++;
        }
        else if (tsum > sum) {
            rpt--;
        }
        else {
            found = true;
            break;
        }
    }
    if (found) {
        if (nums[lpt].second < nums[rpt].second) {
            cout << nums[lpt].second << " " << nums[rpt].second << endl;
        }
        else {
            cout << nums[rpt].second << " " << nums[lpt].second << endl;
        }
    }
    else {
        cout << "IMPOSSIBLE" << endl;
    }
    return 0;
}