#include <bits/stdc++.h>
using namespace std;
bool isSafe(vector<vector<char>> &board, int &i, int &j)
{
    for (int k = 0; k < i; k++)
    {
        if (board[k][j] == '1')
            return false;
    }
    int k = i - 1, l = j - 1;
    while (k >= 0 && l >= 0)
    {
        if (board[k][l] == '1')
            return false;
        k--;
        l--;
    }
    k = i - 1, l = j + 1;
    while (k >= 0 && l >= 0)
    {
        if (board[k][l] == '1')
            return false;
        k--;
        l++;
    }
    return true;
}
void findPath(vector<vector<char>> &board, int &ans, int i)
{
    if (i == board.size())
    {
        for (int a = 0; a < board.size(); a++)
        {
            for (int b = 0; b < board.size(); b++)
            {
                if (board[a][b] == '1')
                {
                    string x = "{" + to_string(a+1) + '-' + to_string(b+1) + '}' + " ";
                    cout << x;
                }
            }
        }
        cout<<" ";
        ans++;
        return;
    }
    for (int k = 0; k < board.size(); k++)
    {
        if (isSafe(board, i, k))
        {
            board[i][k] = '1';
            findPath(board, ans, i + 1);
            board[i][k] = '0';
        }
    }
}
int main()
{
    int n;
    cin >> n;
    vector<vector<char>> board;
    vector<char> help;
    for (int i = 0; i < n; i++)
    {
        help.push_back('0');
    }
    for (int i = 0; i < n; i++)
    {
        board.push_back(help);
    }
    int ans = 0;
    findPath(board, ans, 0);
    cout << endl<<ans;
    return 0;
}