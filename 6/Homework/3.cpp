#include<bits/stdc++.h>
using namespace std;

int n, sum;
int nums[200010];
int sums[200010];

int main(void){
    cin >> n >> sum;
    int s = 0;
    for (int i = 0; i < n; i++) {
        int input;
        cin >> input;
        s += input;
        sums[i+1] = s;
    }

    int counter = 0;
    for (int i = 1; i <= n; i++) {
        for (int j = i; j <= n; j++) {
            if (sums[j] - sums[i-1] == sum) {
                counter++;
            }
        }
    }
    cout << counter << endl;
    return 0;
}