// a. In any cell, the piece moves like a knight. But out of the possible 8 moves for a knight, only the positive ones are valid i.e. both row and column must increase in a move.

// b. On the walls (4 possible walls), the piece can move like a rook as well (in addition of knight moves). But, only the positive moves are allowed i.e. as a rook, piece can move any number of steps horizontally or vertically but in a manner, such that row or column must increase.

// c. On the diagonals (2 possible diagonals), the piece can move like a bishop as well (in addition to the knight and possibly rook moves). But, only the positive moves are allowed i.e. as a bishop, piece can move in a way such that row and column must increase.

#include <bits/stdc++.h>
using namespace std;
vector<string> ans;
bool chk = 0;
bool r = 0;
void findDiffPath(vector<vector<int>> &b, int i, int j, string help)
{
    if (chk == 1 || i >= b.size() || j >= b.size())
        return;
    if (i == b.size() - 1 && j == b.size() - 1)
    {
        help += "{" + to_string(i) + "-" + to_string(j) + "}";
        ans.push_back(help);
        return;
    }
    // horse --->K
    findDiffPath(b, i + 2, j + 1, help + "{" + to_string(i) + "-" + to_string(j) + "}" + "K");
    findDiffPath(b, i + 1, j + 2, help + "{" + to_string(i) + "-" + to_string(j) + "}" + "K");
    // elephent ---> R
    
    findDiffPath(b, i + 1, j, help + "{" + to_string(i) + "-" + to_string(j) + "}" + "R");
    findDiffPath(b, i, j + 1, help + "{" + to_string(i) + "-" + to_string(j) + "}" + "R");
    // camel -- > B
    findDiffPath(b, i + 1, j + 1, help + "{" + to_string(i) + "-" + to_string(j) + "}" + "B");
}
int main()
{
    int n;
    cin >> n;
    vector<int> v;
    vector<vector<int>> b;
    for (int i = 0; i < n; i++)
    {
        v.push_back(0);
    }

    for (int i = 0; i < n; i++)
    {
        b.push_back(v);
    }
    findDiffPath(b, 0, 0, "");
    for (auto i : ans)
        cout << i << " ";
    cout << endl
         << ans.size();
    return 0;
}

import java.util.*;
import java.util.*;
public
class Main
{
    static int c = 0;
public
    static void main(String args[])
    {
        Scanner sc = new Scanner(System.in);
        int n = sc.nextInt();
        printpath(n - 1, n - 1, 0, 0, "");
        System.out.println();
        System.out.print(c);
    }
public
    static void printpath(int re, int ce, int cr, int cc, String ans)
    {
        if (cr == re && cc == ce)
        {
            System.out.print(ans + "{" + cr + "-" + cc + "}" + " ");
            c++;
            return;
        }
        if (cr > re || cc > ce)
        {
            return;
        }

        printpath(re, ce, cr + 2, cc + 1, ans + "{" + cr + "-" + cc + "}" + "K");
        printpath(re, ce, cr + 1, cc + 2, ans + "{" + cr + "-" + cc + "}" + "K");
        if ((cr == 0 || cc == 0) || (cr == re || cc == ce))
        {
            for (int i = 1; i <= re; i++)
            {
                printpath(re, ce, cr, cc + i, ans + "{" + cr + "-" + cc + "}" + "R");
            }
            for (int i = 1; i <= re; i++)
            {
                printpath(re, ce, cr + i, cc, ans + "{" + cr + "-" + cc + "}" + "R");
            }
        }
        if ((cr == cc) || (cr + cc) == re)
        {
            for (int i = 1; i <= re; i++)
            {
                printpath(re, ce, cr + i, cc + i, ans + "{" + cr + "-" + cc + "}" + "B");
            }
        }
    }
}
