#include<bits/stdc++.h>
using namespace std;

int N;
int flowers[110];

int main(void){
    cin >> N;
    for (int i = 0; i < N; i++) {
        cin >> flowers[i];
    }
    int counter = N;
    for (int i = 0; i < N - 1; i++) {
        int sum = flowers[i];
        for (int j = i + 1; j < N; j++) {
            sum += flowers[j];
            double avg = (double)sum / (j-i+1);
            for (int k = i; k <= j; k++) {
                if (avg == flowers[k]) {
                    counter++;
                    break;
                }
            }
        }
    }
    cout << counter << endl;
    return 0;
}