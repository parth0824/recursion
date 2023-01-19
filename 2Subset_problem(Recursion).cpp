#include <bits/stdc++.h>
using namespace std;
void call(vector<int> &v, int &t, int i, int sum, vector<int> help, vector<vector<int>> &ans)
{
    if (i == v.size())
    {
        if (sum == t)
            ans.push_back(help);
        return;
    }
    help.push_back(v[i]);
    call(v, t, i + 1, sum + v[i], help, ans);
    help.pop_back();
    call(v, t, i + 1, sum, help, ans);
}
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    int t;
    cin >> t;
    vector<vector<int>> ans;
    call(v, t, 0, 0, {}, ans);
    for (auto i : ans)
    {
        for (auto j : i)
            cout << j << " ";
        cout << " ";
    }
    cout << endl
         << ans.size() << endl;
    return 0;
}