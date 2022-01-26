#include <bits/stdc++.h>
using namespace std;

const int maxN=1e3;

int a[maxN+1];
int dp[maxN+1][maxN+1]; // dp[i][k]: gcd(a[i], a[i+1], ..., a[i+k-1])
int ST[maxN<<2|1];

int gcd(int a, int b){
    if (a<b) swap(a,b);
    if (b==0) return a;
    return gcd(b, a%b);
}

void update(int rt, int l, int r, int id, int v) {
    if (id>r||id<l) return;
    if (l==r) {
        ST[rt]=v;
        return ;
    }

    int mid=(l+r)>>1;
    update(rt<<1, l, mid, id, v);
    update(rt<<1|1, mid+1,r, id, v);
    ST[rt] = gcd(ST[rt<<1], ST[rt<<1|1]);
}

int get(int rt, int l, int r, int u, int v) {
    if (u>r||v<l) return 0;
    if (u<=l&&r<=v) {
        return ST[rt];
    }

    int mid=(l+r)>>1;
    int lb=get(rt<<1, l, mid, u, v);
    int rb=get(rt<<1|1, mid+1,r, u, v);
    return gcd(lb,rb);
}

int main() {

    freopen("in.txt", "r", stdin);

    int n, k;
    cin>>n>>k;

    for (int i=1; i<=n; ++i) {
        cin>>a[i];
        update(1,1,n,i, a[i]);
    }

    int res=-1;
    for (int j=1; j<=n-k+1; ++j) {
        res=max(res, get(1,1,n,j,j+k-1));
    }
    cout <<res<<endl;

    return 0;
}