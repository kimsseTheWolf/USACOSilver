#include<bits/stdc++.h>
using namespace std;

int K, N;
int maxSpeeds[1000010];

int calcSum(int a, int b) {
    return ((a + b) * (abs(b - a) + 1)) / 2;
}

int calculateBestTime(int maxSpeed) {
    int currDis = 0, currSpeed = 1, step = 0;
    // cout << "Start while loop" << endl;
    while (currDis <= K) {
        if (K - (currDis + currSpeed) < calcSum(currSpeed, maxSpeed) && currSpeed > 1) {
            // means decrease the speed
            currSpeed--;
        }
        else if (K - (currDis + currSpeed) >= calcSum(currSpeed, maxSpeed)) {
            currSpeed++;
        }
        else {
            // cout << calcSum(currSpeed, maxSpeed) << endl;
            continue;
        }
        cout << "CurrSpeed: " << currSpeed << endl;
        currDis += currSpeed;
        step++;
        // cout << "exec" << endl;
    }
    return step;
}

int main(void){
    cin >> K >> N;
    for (int i = 0; i < N; i++) {
        cin >> maxSpeeds[i];
    }
    for (int i = 0; i < N; i++) {
        // cout << "Exec for" << endl;
        cout << calculateBestTime(maxSpeeds[i]) << endl;
    }
    return 0;
}