#include <bits/stdc++.h>

using namespace std;

int num = 0;
vector<long long> results;

int main()
{
    cin >> num;
    for (int k = 0; k < num; k++) {
        // all variables
        int N;
        cin >> N;
        vector<long long> initHeight(N); // must define length here
        vector<long long> gRate(N);
        vector<long long> request(N);

        // input 
        // initial height
        for (int i = 0; i < N; i++){
            cin >> initHeight[i];
        }
        // every plant's growth rate
        for (int i = 0; i < N; i++){
            cin >> gRate[i];
        }
        // requirements
        for (int i = 0; i < N; i++){
            cin >> request[i];
        }

        // process

        long long low = 0, high = 1e9;

        while (low < high){
            long long mid = low + (high - low) / 2;
            vector<long long> count(N, 0);

            for (int i = 0; i < N; i++){
                // calculate each expected height
                long long expectedHeight = initHeight[i] + mid * gRate[i];
                for (int j = 0; j < N; j++){
                    if (expectedHeight < initHeight[j] + mid * gRate[j] && i != j){ // AVOID SELF!!!
                        // count all the plants that taller than this one
                        count[i]++;
                    }
                }
            }

            // Requirement check
            bool valid = true;
            for (int i = 0; i < N; i++){
                if (count[i] != request[i]){
                    valid = false;
                    break;
                }
            }

            if (valid){
                // find even smaller numbers
                high = mid;
            }
            else{
                // increase the day time cause not met
                low = mid + 1;
            }
        }

        if (low == 1e9) {
            results.push_back(-1);
        }
        else {
            results.push_back(low);
        }
    }
    for (int i = 0; i < results.size(); i++) {
        cout << results[i] << endl;
    }
    return 0;
}