#include<bits/stdc++.h>

using namespace std;

int k;
vector<vector<int>> arrs;

void merge2arr(vector<int>& arr1, vector<int>& arr2) {
    int m=arr1.size(), n=arr2.size();
    for (int i=0;i<n;i++) arr1.push_back(0);
    int i=m-1, j=n-1, k=m+n-1;
    while (k>=0){
        if (j<0 || (i>=0 && arr1[i]>arr2[j])){
            arr1[k--]=arr1[i--];
        }
        else {
            arr1[k--]=arr2[j--];
        }
    }
}

void mergeKarr() {
    if (k==0)
        return;
    int interval=1;
    while(interval<k){
        for (int i=0;i+interval<k;i+=(interval*2)){
            merge2arr(arrs[i], arrs[i+interval]);
        }
        interval*=2;
    }
}

int main(){

    freopen("in.txt", "r", stdin);
    cin >> k;
    cin.ignore();
    for (int i=0;i<k;i++) {
        string s;
        getline(cin, s);
        vector<int> temp;
        for (char c: s) {
            if (c==' ') continue;
            temp.push_back(c-'0');
        }
        arrs.push_back(temp);
    }
    mergeKarr();
    for (auto i : arrs[0]){
        cout << i << " ";
    }
    return 0;
}