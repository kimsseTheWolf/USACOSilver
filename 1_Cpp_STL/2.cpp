// http://www.usaco.org/index.php?page=viewproblem2&cpid=666

#include<iostream>
#include<algorithm>
#include<stdio.h>

using namespace std;

int locations[100001] = {};

int main() {
    freopen("haybales.in", "r", stdin);
    freopen("haybales.out", "w", stdout);
    // input locations
    int locationNum = 0, intervalNum = 0;
    cin >> locationNum >> intervalNum;
    for (int i = 0; i < locationNum; i++) {
        cin >> locations[i];
    }

    sort(locations, locations+locationNum);

    // trigger distances
    for (int i = 0; i < intervalNum; i++) {
        int leftBond = 0, rightBond = 0;
        bool rightEndInclusive = true;
        cin >> leftBond >> rightBond;
        // check left bond
        int leftLoc = lower_bound(locations, locations + locationNum, leftBond) - locations;
        int rightLoc = lower_bound(locations, locations + locationNum, rightBond) - locations;
        if (locations[leftLoc] != leftBond) {
            // found the next largest, verify the result
            if (leftLoc > rightLoc) {
                // no element, skip
                cout << 0 << endl;
                continue;
            }
        }

        // check rigtht bond
        if (locations[rightLoc] != rightBond) {
            rightEndInclusive = false;
        }

        // calculate distance
        int distance = rightLoc - leftLoc;
        if (rightEndInclusive) {
            distance++;
        }
        cout << distance << endl;
    }

    return 0;
}