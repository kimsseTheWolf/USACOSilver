#include<bits/stdc++.h>
using namespace std;
int days, orders;
vector<pair<int, int>> roomDetails;


int main(void){ 
    cin >> days >> orders;
    for (int i = 0; i < days; i++) {
        int maxRoom;
        cin >> maxRoom;
        roomDetails.push_back({maxRoom, 0});
    }
    for (int i = 1; i <= orders; i++) {
        int needRooms, start, end;
        cin >> needRooms >> start >> end;
        // check are the rooms available
        for (int j = start; j <= end; j++) {
            if (roomDetails[j].first - roomDetails[j].second < needRooms) {
                // means not enough, print and exit
                cout << -1 << endl;
                cout << i << endl;
                return 0;
            }
        }
        // made changes
        for (int j = start; j <= end; j++) {
            roomDetails[j].second += 1;
        }
    }
    cout << 0 << endl;
    return 0;
}