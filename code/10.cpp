#include <bits/stdc++.h>
using namespace std;

#define i2 array<int,2>

const int maxN=1000;

int m, n;
int a[maxN+1][maxN+1];
int **col0; 
int **col1;

bool valid(int i, int j) {
    return (1<=i&&i<=m)&&(1<=j&&j<=n);
}

void inp() {

    cin>>m>>n;

    col0=new int*[m+1];
    col1=new int*[m+1];
    for (int i=0;i<=m; ++i) {
        col0[i]=new int[n+1];
        col1[i]=new int[n+1];
    }


    for (int i=1; i<=m; ++i) {
        for (int j=1; j<=n; ++j) {
            cin>>a[i][j];

            if(a[i][j]==0) {
                col0[i][j]=1;
                col1[i][j]=0;
                if (a[i][j]==a[i-1][j]&&i>1) col0[i][j]=col0[i-1][j]+1;
            }
            else {
                col1[i][j]=1;
                col0[i][j]=0;
                if (a[i][j]==a[i-1][j]&&i>1) col1[i][j]=col1[i-1][j]+1;
            }
        }
    }
}

int sol(int **col) {
    int res=1;
    for (int i=1; i<=m; ++i) {

        stack<i2> stk;
        for (int j=1; j<=n; ++j) {
            if (stk.empty() || col[i][j]>=stk.top()[0]) {
                stk.push({col[i][j], j});
            }
            else {
                i2 tmp;
                while(!stk.empty()&&col[i][j]<stk.top()[0]) {
                    tmp=stk.top(); stk.pop();
                    int r = min(tmp[0], j-tmp[1]);
                    res=max(r, res);
                }
                stk.push({col[i][j], tmp[1]});
            }
        }

        while(!stk.empty()) {
            i2 tmp=stk.top(); stk.pop();
            int r = min(tmp[0], n-tmp[1]+1);
            res=max(r, res);
        }
        
    }
    return res;
}

int main() {

    freopen("in.txt", "r", stdin);

    inp();
    
    int res=1;
    res=max(res, sol(col0));
    res=max(res, sol(col1));

    cout <<res<<"\n";

    return 0;
}