// https://www.luogu.com.cn/problem/P1102

#include<iostream>
#include<algorithm>

using namespace std;

int nums[1000001] = {0};

int main() {
    int numNum = 0, C = 0;
    cin >> numNum >> C;
    for (int i = 0; i < numNum; i++) {
        cin >> nums[i];
    }
    sort(nums, nums+numNum);
    // iterate to calculate
    long long counter = 0;
    for (int i = 0; i < numNum; i++) {
        int targetNum = nums[i] - C;
        // find the range of the target numbers
        if (targetNum < nums[0]) {
            continue;
        }
        int leftLoc = lower_bound(nums, nums+numNum, targetNum) - nums;
        if (nums[leftLoc] != targetNum) {
            // means no such number, continue
            continue;
        }
        int rightLoc = upper_bound(nums, nums+numNum, targetNum) - nums;
        // cout << "Current num: " << nums[i] << " LeftLoc: " << leftLoc << " RightLoc: " << rightLoc << endl;
        counter += rightLoc - leftLoc;
    }
    cout << counter << endl;
    return 0;
}