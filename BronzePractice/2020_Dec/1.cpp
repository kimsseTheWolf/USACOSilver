#include<bits/stdc++.h>
using namespace std;

vector<int> nums;

bool checkSequence(vector<int> target, int aLoc, int bLoc, int cLoc) {
    // a+b
    auto result = find(target.begin(), target.end(), target[aLoc]+target[bLoc]);
    if (result == target.end()) {
        // cout << "a+b" << endl;
        return false;
    }
    int dis = distance(target.begin(), result);
    if (dis == aLoc or dis == bLoc or dis == cLoc) {
        // cout << "a+b" << endl;
        return false;
    }
    target[distance(target.begin(), result)] = -1;

    // a+c
    result = find(target.begin(), target.end(), target[aLoc] + target[cLoc]);
    if (result == target.end()){
        // cout << "a+c" << endl;
        return false;
    }
    dis = distance(target.begin(), result);
    if (dis == aLoc or dis == bLoc or dis == cLoc){
        // cout << "a+c" << endl;
        return false;
    }
    if (dis == target.size() - 1 && target[dis] != target[aLoc] + target[cLoc]) {
        // cout << "a+c" << endl;
        return false;
    }
    target[dis] = -1;

    // b+c
    auto result2 = find(target.begin(), target.end(), target[bLoc] + target[cLoc]);
    // cout << "result: " << target[bLoc] + target[cLoc] << endl;
    if (result2 == target.end()){
        // cout << "b+c end" << endl;
        return false;
    }
    dis = distance(target.begin(), result2);
    if (dis == bLoc or dis == bLoc or dis == cLoc){
        // cout << "b+c inside abc" << endl;
        return false;
    }
    if (dis == target.size() - 1 && target[dis] != target[bLoc] + target[cLoc]){
        // cout << "b+c last one" << endl;
        return false;
    }
    target[dis] = -1;

    // a+b+c
    result = find(target.begin(), target.end(), target[aLoc] + target[bLoc] + target[cLoc]);
    if (result == target.end()){
        // cout << "a+b+c" << endl;
        return false;
    }
    dis = distance(target.begin(), result);
    if (dis == aLoc or dis == bLoc or dis == cLoc){
        // cout << "a+b+c" << endl;
        return false;
    }
    target[dis] = -1;
    // cout << "pass" << endl;
    return true;
}

int main(void){
    for (int i = 0; i < 7; i++) {
        int input;
        cin >> input;
        nums.push_back(input);
    }
    sort(nums.begin(), nums.end());
    for (int i = 2; i < 7; i++) {
        // cout << i << ": " << endl;
        if (checkSequence(nums, 0, 1, i)) {
            cout << nums[0] << " " << nums[1] << " " << nums[i];
            return 0;
        }
    }
    return 0;
}