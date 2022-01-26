#include <bits/stdc++.h>
using namespace std;

#define i2 array<int,2>

const int maxN=3e4;

int a[maxN+1], ac[maxN+1];

int main() {
    freopen("in.txt", "r", stdin);

    int n;
    cin>>n;

    ac[0]=0;
    for (int i=1; i<=n; ++i) {
        cin>>a[i];
        ac[i]=ac[i-1]+a[i];
    }

    stack<i2> stk;
    int res=0;
    for (int i=1; i<=n; ++i) {
        if (stk.empty()) stk.push({a[i], i});
        else {
            i2 tmp;
            while (!stk.empty() && stk.top()[0]<a[i]) {
                tmp = stk.top(); stk.pop();
            }
            if (stk.empty()) {
                res += min(a[i], tmp[0])*(i-tmp[1]-1) - (ac[i-1]-ac[tmp[1]]);
            }
            stk.push({a[i], i});
        }
    }

    if (!stk.empty()) {
        i2 tmp = stk.top(); stk.pop();
        while (!stk.empty()) {
            i2 tmp2=stk.top(); stk.pop();
            res += min(tmp2[0], tmp[0])*(tmp2[1]-tmp[1]-1) - (ac[tmp2[1]]-ac[tmp[1]]);
            tmp=tmp2;
        }
    }

    cout <<res<<"\n";

    return 0;
}