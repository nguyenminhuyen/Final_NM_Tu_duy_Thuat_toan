#include <bits/stdc++.h>
using namespace std;

const int maxN=1e6;

int n;
vector<int> primes;
int isPrime[maxN+1];

void prime_sieve() {
    for (int i=0; i<=maxN; ++i) isPrime[i]=i;
    for (int i=2; i<=maxN; ++i) {
        if (isPrime[i]==i) {
            if (isPrime[i]!=2){
                primes.push_back(i);
            }
            for (int j=i; j<=maxN/i; ++j) {
                isPrime[j*i]=i;
            }
        }
    }
}

int main() {

    //freopen("in.txt", "r", stdin);

    prime_sieve();

    cin>>n;

    int res=0;
    int N=primes.size();
    int i=0,j=N-1;
    while(i<=j){
        if (primes[i]+primes[j]>2*n) j--;
        else {
            res+=(j-i+1); 
            i++;
        }
    }

    if (4<=2*n) res++;

    cout << res<<"\n";

    return 0;
}