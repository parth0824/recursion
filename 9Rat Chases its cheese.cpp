#include <bits/stdc++.h>
using namespace std;
vector<string> fans;
bool chk = 0;
void findPath(vector<string> &v, int i, int j, vector<string> &ans)
{
    if (chk == 1 || v[i][j] == 'X' || i < 0 || j < 0 || i >= v.size() || j >= v[0].size())
        return;
    if (i == v.size() - 1 && j == v[0].size() - 1)
    {
        chk = 1;
        ans[i][j] = '1';
        fans = ans;
        return;
    }
    v[i][j] = 'X';
    ans[i][j] = '1';

    findPath(v, i + 1, j, ans);
    findPath(v, i - 1, j, ans);
    findPath(v, i, j + 1, ans);
    findPath(v, i, j - 1, ans);

    ans[i][j] = '0';
    v[i][j] = 'O';
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<string> v;
    vector<string> ans;
    for (int i = 0; i < n; i++)
    {
        string help = "";
        string help1 = "";
        for (int j = 0; j < m; j++)
        {
            char x;
            cin >> x;
            help += x;
            help1 += '0';
        }
        v.push_back(help);
        ans.push_back(help1);
    }
    if (v[0][0] == 'X' || v[n - 1][m - 1] == 'X')
    {
        cout << "NO PATH FOUND";
        return 0;
    }



    findPath(v, 0, 0, ans);



    
    if (fans.size() == 0)
    {
        cout << "NO PATH FOUND";
        return 0;
    }
    for (auto i : fans)
    {
        for (auto j : i)
        {
            if (j == '1')
                cout << j << " ";
            else
                cout << 0 << " ";
        }
        cout << endl;
    }
    return 0;
}
