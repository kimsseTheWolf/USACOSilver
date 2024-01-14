#include<bits/stdc++.h>
using namespace std;

unordered_map<char, int> alphabet;
string aplh;
string word;

int main(void){
    cin >> aplh;
    cin >> word;
    for (int i = 0; i < aplh.length(); i++) {
        alphabet[aplh[i]] = i;
    }
    int lastLocation = alphabet[word[0]];
    int counter = 1;
    for (int i = 1; i < word.length(); i++) {
        if (alphabet[word[i]] <= lastLocation) {
            counter++;
        }
        lastLocation = alphabet[word[i]];
    }
    cout << counter << endl;
    return 0;
}