#include <bits/stdc++.h>
using namespace std;

const int maxN=1e3;

int n;
vector<int> primes;

int g(int a){
    int res=0;
    for (int i:primes) {
        if (i>a) break;
        auto it = lower_bound(primes.begin(), primes.end(), 2*a-i);
        if (*it==2*a-i) res++;
    }
    return res;
}

void prime_sieve() {
    int isPrime[maxN+1];
    for (int i=0; i<=maxN; ++i) isPrime[i]=i;
    for (int i=2; i<=maxN; ++i) {
        if (isPrime[i]==i) {
            primes.push_back(i);
            for (int j=i; j<=maxN/i; ++j) {
                isPrime[j*i]=i;
            }
        }
    }
}

int main() {

    freopen("in.txt", "r", stdin);

    prime_sieve();

    cin>>n;

    int res=0;
    for (int i=2; i<=n; ++i) {
        res+=g(i);
    }

    cout << res<<"\n";

    return 0;
}