#include <bits/stdc++.h>
using namespace std;

const int maxN=1e6;

int Z[maxN*2+2];

void Z_algo(string s) {
    int n = s.size();
    int l = 0, r = 0;
    for (int i = 1; i < n; ++i)
    {
        if (i <= r)
            Z[i] = min(Z[i-l], r-i+1);
        while (i + Z[i] < n && s[Z[i]] == s[i+Z[i]])
            ++Z[i];
        if (i + Z[i] - 1 > r)
        {
            l = i;
            r = i + Z[i] - 1;
        }
    }
}

int main() {

    freopen("in.txt", "r", stdin);

    string a,b;
    cin>>a>>b;
    int n=a.size(), m=b.size();
    b+="!";
    b+=a;

    Z_algo(b);

    for (int i=m+1; i<m+n+1; ++i) {
        if (Z[i]==m) cout << i-m << " ";
    }

    return 0;
}