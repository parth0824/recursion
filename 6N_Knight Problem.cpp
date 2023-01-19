#include <bits/stdc++.h>
using namespace std;
int Ans = 0;
bool isSafe(vector<vector<char>> &b, int i, int j)
{
    if (i - 2 >= 0 && j - 1 >= 0 && b[i - 2][j - 1] == '1')
        return false;
    if (i - 2 >= 0 && (j + 1) < b.size() && b[i - 2][j + 1] == '1')
        return false;
    if (i - 1 >= 0 && j + 2 < b.size() && b[i - 1][j + 2] == '1')
        return false;
    if (i + 1 < b.size() && j + 2 < b.size() && b[i + 1][j + 2] == '1')
        return false;
    if (i - 1 >= 0 && j - 2 >= 0 && b[i - 1][j - 2] == '1')
        return false;
    if (i + 1 < b.size() && j + 2 < b.size() && b[i + 1][j - 2] == '1')
        return false;
    if (i + 2 < b.size() && j - 1 >= 0 && b[i + 2][j - 1] == '1')
        return false;
    if (i + 2 < b.size() && j - 2 >= 0 && b[i + 2][j - 2] == '1')
        return false;
    return true;
}
void findPath(vector<vector<char>> &board, int count, int i, int j)
{
    if (count == board.size())
    {
        for (int a = 0; a < board.size(); a++)
        {
            for (int b = 0; b < board.size(); b++)
            {
                if (board[a][b] == '1')
                {
                    string x = "{" + to_string(a) + '-' + to_string(b) + '}' + " ";
                    cout << x;
                }
            }
        }
        cout << " ";
        Ans++;
        return;
    }
    for (int k = i; k < board.size(); k++)
    {
        for (int l = j; l < board.size(); l++)
        {
            if (isSafe(board, k, l))
            {
                board[k][l] = '1';
                findPath(board, count + 1, k, l + 1);
                board[k][l] = '0';
            }
        }
        j = 0;
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

    findPath(board, 0, 0, 0);
    cout << endl
         << Ans;
    return 0;
}