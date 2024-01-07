#include<bits/stdc++.h>
using namespace std;

vector<string> words;
int N, L;

int main(void){
    freopen("word.in", "r", stdin);
    freopen("word.out", "w", stdout);
    cin >> N >> L;
    for (int i = 0; i < N; i++) {
        string content;
        cin >> content;
        words.push_back(content);
    }

    int length = 0;
    for (int i = 0; i < N; i++) {
        if (length + words[i].length() > L) {
            // switch to next line
            cout << endl;
            cout << words[i];
            length = words[i].length();
        }
        else {
            if (i != 0) {
                cout << " ";
            }
            cout << words[i];
            length += words[i].length();
        }
    }
    return 0;
}