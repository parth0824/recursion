#include <bits/stdc++.h>
using namespace std;
vector<vector<int>> ans;
bool c = 0;
bool chk(vector<vector<int>> &s, int i, int j, int k){
    for (int l = 0; l < 9; l++){
        if (s[i][l] == k)return false;
        if (s[l][j] == k)return false;
        if (s[(3 * (i / 3)) + (l % 3)][(3 * (j / 3)) + (l / 3)] == k)return false;
    }
    return true;
}
void solve(vector<vector<int>> &b, int n, int m){
    if(c == 1)return ;
    for (int i = n; i < 10; i++){
        if(i == 9){
            c = 1;
            ans = b;
            return ;
        }
        for (int j = m; j < 9; j++){
            if (b[i][j] == 0){   
                bool x = 0;
                for (int k = 1; k <= 9; k++){
                    if (chk(b, i, j, k)){
                        x = 0;
                        b[i][j] = k;
                        solve(b, i, j+1);
                        b[i][j] = 0;
                    }
                }
                if(x == 0)return ;
            }
        }
        m = 0;
    }
}
int main(){
    int n;cin >> n;
    vector<vector<int>> b;
    for (int i = 0; i < 9; i++){
        vector<int> help;
        for (int j = 0; j < 9; j++){
            int x;cin >> x;
            help.push_back(x);
        }
        b.push_back(help);
    }
    solve(b, 0, 0);
    for (auto i : ans){
        for (auto j : i)
            cout << j << " ";
        cout << endl;
    }
    return 0;
}