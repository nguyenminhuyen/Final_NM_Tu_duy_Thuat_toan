#include <bits/stdc++.h>
using namespace std;

const int maxN=5e4;

int n, m;
int a[maxN+1];
int ST[maxN<<2|1];

void nen() {
    m=-1;
    vector<int> v;
    for (int i=1; i<=n ;++i) v.push_back(a[i]);
    sort(v.begin(), v.end());
    for (int i=1; i<=n; ++i) {
        a[i] = lower_bound(v.begin(), v.end(), a[i])-v.begin()+1;
        m = max(a[i], m);
    }
}

void update(int rt, int l, int r, int id, int v) {
    if (id>r || id<l) return ;
    if (l==r) {
        ST[rt]+=v;
        return ;
    }

    int mid = (l+r)>>1;
    update(rt<<1, l, mid, id, v);
    update(rt<<1|1, mid+1, r, id, v);
    ST[rt] = ST[rt<<1] + ST[rt<<1|1];
}

int get(int rt, int l, int r, int u, int v) {
    if (l>v||r<u) return 0;
    if (u<=l&&r<=v) return ST[rt];

    int mid=(l+r)>>1;
    int lb=get(rt<<1, l, mid, u, v);
    int rb=get(rt<<1|1, mid+1, r, u, v);
    return lb+rb;
}

int main() {
    freopen("in.txt", "r", stdin);

    cin>>n;

    for (int i=1; i<=n; ++i) cin>>a[i];

    nen(); 
    //for (int i=1; i<=n; ++i) cout << a[i]<<" ";
    //cout <<"\n";

    for (int i=1; i<=n; ++i) update(1,1,m, a[i], 1);

    int res=0;
    for (int i=n; i>0; --i) {
        update(1,1,m, a[i], -1);
        if (a[i]==m) continue;
        res += get(1,1,m, a[i]+1, m);
    }
    cout <<res << "\n";

    return 0;
}