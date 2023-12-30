#include<bits/stdc++.h>
using namespace std;

pair<int, int> nums[5010];
int N, sum;

int main(void){
    cin >> N >> sum;
    if (N < 3) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    for (int i = 0; i < N; i++) {
        nums[i].second = i + 1;
        cin >> nums[i].first;
    }
    sort(nums, nums+N);

    for (int i = 0; i < N; i++) {
        int lpt = 0, rpt = N - 1;
        while (lpt < rpt) {
            // skip i
            if (lpt == i) {
                lpt++;
            }
            if (rpt == i) {
                rpt--;
            }
            int s = nums[i].first + nums[lpt].first + nums[rpt].first;
            if (s < sum) {
                lpt++;
            }
            else if (s > sum) {
                rpt--;
            }
            else {
                cout << nums[i].second << " " << nums[lpt].second << " " << nums[rpt].second << endl;
                return 0;
            }
        }
    }
    cout << "IMPOSSIBLE" << endl;
    return 0;
}