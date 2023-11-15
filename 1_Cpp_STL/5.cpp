// https://cses.fi/problemset/task/1084

#include<iostream>
#include<algorithm>

using namespace std;

int applicants[200001] = {0};
int apartments[200001] = {0};

int main() {
    int applicantsNum = 0, apartmentNum = 0, diff = 0;
    cin >> applicantsNum >> apartmentNum >> diff;
    for (int i = 0; i < applicantsNum; i++) {
        cin >> applicants[i];
    }
    for (int i = 0; i < apartmentNum; i++) {
        cin >> apartments[i];
    }

    sort(apartments, apartments + apartmentNum);

    // calculate the valid data
    int counter = 0;
    for (int i = 0; i < applicantsNum; i++) {
        int upper = lower_bound(apartments, apartments + apartmentNum, applicants[i]) - apartments;
        int lower = upper - 1;
        // override the one that has smallest difference
        bool isUpper = true;
        if (abs(applicants[i] - apartments[upper]) <= diff || abs(applicants[i] - apartments[lower]) <= diff) {
            if (abs(applicants[i] - apartments[upper]) <= abs(applicants[i] - apartments[lower])) {
                // apartments[upper] = -114514;
                counter++;
            }
            else {
                // apartments[lower] = -114514;
                counter++;
            }
        }
        sort(apartments, apartments + apartmentNum);
    }
    cout << counter << endl;
    return 0;
}