// 超时

#include<bits/stdc++.h>
using namespace std;

int N;
int sums[200010];

int main(void){
    cin >> N;
    int sum = 0;
    for (int i = 1; i <= N; i++) {
        int num;
        cin >> num;
        sum += num;
        sums[i] = sum;
    }
    int counter = 0;
    for (int i = 0; i <= N; i++) {
        for (int j = i + 1; j <= N; j++) {
            int result = sums[j] - sums[i];
            counter += (result % N == 0);
        }
    }
    cout << counter << endl;
    return 0;
}