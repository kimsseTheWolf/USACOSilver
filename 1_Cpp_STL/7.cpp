#include<bits/stdc++.h>
using namespace std;

int x, n;
int p[200010];
int e[200010];
set<int> st;
int delta = 0;
stack<int> stk;

int main(void){
    cin >> x >> n;
    for (int i = 1; i <= n; i++) {
        cin >> p[i];
        e[i] = p[i];
        st.insert(p[i]);
    }
    st.insert(0);
    st.insert(x);
    sort(p+1, p+n+1);
    p[n+1] = x;
    for (int i = 1; i <= n + 1; i++) {
        delta = max(delta, p[i] - p[i-1]);
    }
    stk.push(delta);

    for (int i = n; i > 1; i--) {
        auto itr = st.lower_bound(e[i]);
        auto pre = itr;
        auto post = itr;
        pre++;
        post--;
        delta = max(delta, *pre - *post);
        stk.push(delta);
        st.erase(itr);
    }

    while (!stk.empty()) {
        cout << stk.top() << " ";
        stk.pop();
    }
    return 0;
}