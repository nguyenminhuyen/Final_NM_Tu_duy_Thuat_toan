#include <bits/stdc++.h>
using namespace std;

#define i2 array<int,2>

const int maxK=1e4;
const int maxN=5e2;

int k;
queue<int> b[maxN+1];
multiset<i2> st;

int main() {
    freopen("in.txt", "r", stdin);
    cin >> k;
    fflush(stdin);
    for (int i=1; i<=k; ++i) {
        string s;
        getline(cin, s);

        for (char c: s) {
            if (c==' ') continue;
            b[i].push(c-'0');
        }
        st.insert({b[i].front(), i});
    }


    while (!st.empty()) {
        auto it=st.begin();
        cout << (*it)[0] << " ";
        
        int id=(*it)[1];
        st.erase(st.begin());
        
        b[id].pop();
        if (!b[id].empty()) st.insert({b[id].front(), id});
    }


    return 0;
}