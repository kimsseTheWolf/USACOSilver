#include<bits/stdc++.h>
using namespace std;

long long nums[200010];
int N;

int main(void){
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> nums[i];
    }
    int localMax = nums[0], globalMax = nums[0];
    for (int i = 1; i < N; i++) {
        localMax = max(nums[i], nums[i]+localMax);
        globalMax = max(globalMax, localMax);
    }
    cout << globalMax << endl;
}