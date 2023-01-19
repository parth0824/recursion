#include <bits/stdc++.h>
using namespace std;
void findPath(int i, int j, vector<vector<char>> &maze, vector<vector<char>> &mazePath)
{
    if (maze[maze.size() - 1][maze[0].size() - 1] == '1' || maze[i][j] == 'X' || i >= maze.size() || j >= maze[0].size())
        return;
    else if ( maze[i][j] != 'X'  && i == maze.size() - 1 && j == maze[0].size() - 1)
    {
        maze[i][j] = '1';
        i++;
        j++;
        mazePath = maze;
        return;
    }
    else
    {
        maze[i][j] = '1';
        findPath(i, j + 1, maze, mazePath);
        findPath(i + 1, j, maze, mazePath);
        maze[i][j] = 'O';
    }
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<char>> maze;
    vector<vector<char>> mazePath;
    for (int i = 0; i < n; i++)
    {
        vector<char> inputV;
        for (int j = 0; j < m; j++)
        {
            char input;
            cin >> input;
            inputV.push_back(input);
        }
        maze.push_back(inputV);
    }
    findPath(0, 0, maze, mazePath);
    if(mazePath.size() == 0){
        cout<<-1<<endl;
        return 0;
    }
    for (auto i : mazePath)
    {
        for (auto j : i)
        {
            if (j != '1')
                cout << 0 << " ";
            else
                cout << 1 << " ";
        }
        cout << endl;
    }
    return 0;
}