#include<bits/stdc++.h>

using namespace std;

void step(vector<vector<string>>& res, int row, int n, vector<int>& queens, vector<bool>& col, vector<bool>& diag1, vector<bool>& diag2){
    if (row==n){
        vector<string> temp;
        for (int i=0;i<n;i++){
            string line="";
            for (int j=0;j<n;j++){
                if (j==queens[i]) line+="Q";
                else line+=".";
            }
            temp.push_back(line);
        }
        res.push_back(temp);
        return;
    }
    for (int i=0;i<n;i++){
        if (!col[i] && !diag1[row-i+n-1] && !diag2[row+i]){
            col[i]=true; diag1[row-i+n-1]=true; diag2[row+i]=true;
            queens[row]=i;
            step(res, row+1, n, queens, col, diag1, diag2);
            col[i]=false; diag1[row-i+n-1]=false; diag2[row+i]=false;
        }
    }
}

vector<vector<string>> solveNQueens(int n) {
    vector<vector<string>> res;
    vector<bool> col(n), diag1(2*n-1), diag2(2*n-1);
    vector<int> queens(n);
    step(res, 0, n, queens, col, diag1, diag2);
    return res;
}

int main(){

    freopen("in.txt", "r", stdin);
    int n; cin >> n;
    vector<vector<string>> res = solveNQueens(n);
    cout << res.size() << endl;
    for (int i=0;i<res.size();i++){
        for (auto line : res[i]){
            cout << line << endl;
        }
        cout << endl;
    }
    return 0;
}