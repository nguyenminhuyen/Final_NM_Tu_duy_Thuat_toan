#include <bits/stdc++.h>
using namespace std;

#define i2 array<int,2>

const int maxN=1e5;

vector<i2> a, b;

bool valid(int i, int n) {
    return 0<=i&&i<n;
}

bool comp(const i2 &a,const i2 &b) {
    return a[0]<b[0];
}

int main() {

    freopen("in.txt", "r", stdin);

    int m,n;
    cin>>m>>n;

    for (int i=1; i<=m; ++i) {
        int tmp;
        cin>>tmp;
        a.push_back({tmp, i});
    }
    for (int i=1; i<=n; ++i) {
        int tmp;
        cin>>tmp;
        b.push_back({tmp, i});
    }
    sort(a.begin(),a.end(), comp);
    sort(b.begin(),b.end(), comp);


    int r=2e9;
    i2 pr;
    for (int i=0; i<m; ++i) {
        int it = upper_bound(b.begin(),b.end(), i2({-a[i][0], 0}),comp)-b.begin();
        if (valid(it, n)) {
            if (r>abs(b[it][0]+a[i][0])) {
                r=abs(b[it][0]+a[i][0]);
                pr={a[i][1], b[it][1]};
            }
        }
        if (valid(it-1, n)) {
            if (r>abs(b[it-1][0]+a[i][0])) {
                r=abs(b[it-1][0]+a[i][0]);
                pr={a[i][1], b[it-1][1]};
            }
        }
    }

    cout <<pr[0] << " " <<pr[1] << "\n";

    return 0;
}