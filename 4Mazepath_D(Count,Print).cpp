#include <bits/stdc++.h>
using namespace std;
void findPath(vector<vector<char>> &board, vector<string> &ans, string help, int i, int j)
{
    if (i >= board.size() || j >= board[0].size())
        return;
    if (i == board.size() - 1 && j == board[0].size() - 1)
    {
        ans.push_back(help);
        return;
    }
    findPath(board, ans, help + 'V', i + 1, j);
    findPath(board, ans, help + 'H', i, j + 1);
    findPath(board, ans, help + 'D', i + 1, j + 1);
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> board;
    vector<char> help;
    for (int i = 0; i < m; i++)
        help.push_back('0');
    for (int i = 0; i < n; i++)
        board.push_back(help);
    vector<string> ans;
    findPath(board, ans, "", 0, 0);
    int cAns = ans.size();
    for (auto i : ans)
    {
        cout << i << " ";
    }
    cout << endl
         << cAns << endl;
    return 0;
}