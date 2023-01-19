#include <bits/stdc++.h>
using namespace std;
void findAll(string &s, string help, int ind, vector<string> &ans)
{
    if (s.size() == 0)
    {
        ans.push_back(help);
        return;
    }
    for (int i = 0; i < s.size(); i++)
    {
        char x = s[i];
        string d = s;
        s.erase(s.begin() + i);
        findAll(s, help + x, ind - 1, ans);
        s = d;
    }
}
int main()
{
    string s;
    cin >> s;
    string h = s;
    sort(s.begin(), s.end());
    vector<string> ans;
    findAll(s, "", s.size(), ans);
    for (auto i : ans)
    {
        if (i > h)
            cout << i << "\n";
    }
    return 0;
}
