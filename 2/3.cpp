// https://www.luogu.com.cn/problem/P1208
// https://www.luogu.com.cn/record/136422801

#include<bits/stdc++.h>
using namespace std;

struct farmer {
    int milk;
    int price;
};

bool comp(farmer a, farmer b) {
    return a.price < b.price;
}

farmer farmers[5002];
int n, m;

int main(void){
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        cin >> farmers[i].price >> farmers[i].milk;
    }

    sort(farmers, farmers+m, comp);

    long long price = 0;
    for (int i = 0; i < m; i++) {
        if (n >= farmers[i].milk) {
            // Can take all
            n -= farmers[i].milk;
            price += farmers[i].milk * farmers[i].price;
        }
        else {
            // take partial
            price += farmers[i].price * n;
            break;
        }
    }
    cout << price << endl;
    return 0;
}