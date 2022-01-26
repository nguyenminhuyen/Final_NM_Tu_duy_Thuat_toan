#include <bits/stdc++.h>
using namespace std;

string s, o_p, p;
map<int, char> atk;

bool sol(int i, int j) {
    //cout << i << " " << j << endl;
    if (i>=s.size()&&j>=p.size()){
        //cout << i << " " << j << endl;
        return true;
    } 
    else if (i>=s.size()||j>=p.size()) {
        //cout << i << " " << j << endl;
        return false;
    }

    if (p[j]=='*') {
        bool res=false;
        if (atk[j]==s[i]) res=res|sol(i+1, j);
        res = res|sol(i, j+1);
        //cout << i << " " << j << endl;
        return res;
    }
    else if (p[j]=='.') {
        return sol(i+1, j+1);
    }
    else {
        if (s[i]!=p[j]){
            //cout << i << " " << j << endl;
            return false;
        } 
        return sol(i+1,j+1);
    }
}

int main() {
    freopen("in.txt", "r", stdin);
    cin>>s>>o_p;
    for (int i=0; i<o_p.size(); ++i) {
        if (i==o_p.size()-1) p+=o_p[i];
        else if (o_p[i+1]!='*') p+=o_p[i];
        else {
            atk[p.size()]=o_p[i];
        }
    }

    if (sol(0,0)) cout <<"true\n";
    else cout<<"false\n";

    return 0;
}