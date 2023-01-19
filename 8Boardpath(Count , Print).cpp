#include <bits/stdc++.h>
using namespace std;
void findAns(vector<int> &v, int &t, int sum, vector<int> help, vector<vector<int>> &ans)
{
    if (sum == t)
    {
        ans.push_back(help);
        return;
    }
    if (sum > t)
    {
        return;
    }
    for (int j = 0; j < v.size(); j++)
    {
        help.push_back(v[j]);
        findAns(v, t, sum + v[j], help, ans);
        help.pop_back();
    }
}
int main()
{
    int n, m;
    cin >> m >> n;
    vector<int> v;
    vector<int> help;
    for (int i = 0; i < n; i++)
        v.push_back(i + 1);
    vector<vector<int>> ans;
    findAns(v, m, 0,  help, ans);
    for (auto i : ans)
    {
        for (auto j : i)
            cout << j;
        cout << " ";
    }
    cout << endl;
    cout << ans.size()<<endl;
    return 0;
}