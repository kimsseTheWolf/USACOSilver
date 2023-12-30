#include<bits/stdc++.h>
using namespace std;

// sample code here for converting bases
// https://blog.csdn.net/weixin_55305220/article/details/123955237
char hexNumConvert(long long num) {
    if (num < 10) {
        return num + '0';
    }
    else {
        return num - 10 + 'A';
    }
}

int charToInt(char num) {
    if (num >= '0' && num <= '9') {
        return num - '0';
    }
    else {
        return num - 'A' + 10;
    }
}

string convertToBase(long long num, int base) {
    stack<char> s;
    string result = "";
    if (num == 0) {
        s.push(0);
    }
    else {
        while (num) {
            s.push(hexNumConvert(num % base));
            num /= base;
        }
    }

    while (!s.empty()) {
        result.push_back(s.top());
        s.pop();
    }
    return result;
}

long long convertToDec(string num, int base) {
    long long result = 0;
    for (int i = 0; i < num.size(); i++) {
        result *= base;
        result += charToInt(num[i]);
    }
    return result;
}

string reverseStr(string content) {
    string result = "";
    for (int i = content.size() - 1; i >= 0; i--) {
        result.push_back(content[i]);
    }
    return result;
}

bool isPalidromic(string num) {
    for (int i = 0; i < num.size() / 2; i++) {
        if (num[i] != num[num.size() - 1 - i]) {
            return false;
        }
    }
    return true;
}

int base;
string num;

int main(void){
    cin >> base >> num;

    // do math
    int counter = 0;
    bool found = false;
    while (counter <= 30) {
        string reversedNum = reverseStr(num);
        string result = convertToBase(convertToDec(num, base) + convertToDec(reversedNum, base), base);
        // cout << num << " " << reversedNum << " " << result << endl;
        if (isPalidromic(result)) {
            found = true;
            break;
        }
        else {
            num = result;
            counter++;
        }
    }
    if (found) {
        cout << "STEP=" << counter+1 << endl;
    }
    else {
        cout << "Impossible!" << endl;
    }
    return 0;
}