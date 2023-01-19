#include <bits/stdc++.h>
using namespace std;
int ans = 0;
void findMaxAns(vector<vector<int>> &v, int n, int m, int sum)
{
    ans = max(ans, sum);
    if (n < 0 || m < 0 || n >= v.size() || m >= v[0].size() || (v[n][m] == 0))
    {
        return;
    }
    int x = v[n][m];
    v[n][m] = 0;
    findMaxAns(v, n, m - 1, sum + x);
    findMaxAns(v, n, m + 1, sum + x);
    findMaxAns(v, n + 1, m, sum + x);
    findMaxAns(v, n - 1, m, sum + x);
    v[n][m] = x;
}
void mm(vector<vector<int>> &v)
{
    for (int i = 0; i < v.size(); i++)
    {
        for (int j = 0; j < v[0].size(); j++)
        {
            if (v[i][j] != 0)
                findMaxAns(v, i, j, 0);
        }
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> v;
    for (int i = 0; i < n; i++)
    {
        vector<int> help;
        for (int j = 0; j < m; j++)
        {
            int x;
            cin >> x;
            help.push_back(x);
        }
        v.push_back(help);
    }
    mm(v);
    cout << endl
         << ans;
    return 0;
}
 