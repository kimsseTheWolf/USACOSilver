// https://www.luogu.com.cn/problem/P2249

#include<iostream>
#include<algorithm>

using namespace std;

int nums[10000001] = {};

int main() {
    int numNum, reqNum;
    cin >> numNum >> reqNum;
    for (int i = 0; i < numNum; i++) {
        cin >> nums[i];
    }
    sort(nums, nums+numNum);
    for (int i = 0; i < reqNum; i++) {
        int targetNum;
        cin >> targetNum;
        int loc = lower_bound(nums, nums+numNum, targetNum) - nums;
        if (loc == numNum || nums[loc] != targetNum){
            cout << -1 << " ";
            continue;
        }
        cout << loc + 1 << " ";
    }
    return 0;
}