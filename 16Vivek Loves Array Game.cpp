// Initially, there is an array, A , containing 'N' float egers.

// In each move, Vivek must divide the array float o  two non-empty contiguous parts such that the sum of the elements in the left part is equal  to the sum of the elements in the right part. If Vivek can make such a move, he gets '1' pofloat ; otherwise, the game ends.

// After each successful move, Vivek have to discards either the left part or the right part and continues playing by using the remaining partition as array 'A'.
#include <bits/stdc++.h>
using namespace std;
int f = 0;
// 1 <= T <= 10 
// 1 <= N <= 17000 
// 0 <= A[i] <= 10^9
void find(vector<int> v, float sum, int l, int r, int ans)
{
    f = max(f, ans);
    if (l >= r)
        return;
    for (int i = l; i <= r; i++)
    {
        float x = sum / 2;
        if (x == v[i])
        {
            find(v, sum / 2, 0, i, ans + 1);
            for (int j = i + 1; j < v.size(); j++)
                v[j] -= v[i];
            find(v, sum / 2, i + 1, v.size(), ans + 1);
        }
    }
}

void testcase()
{
    int n;
    cin >> n;
    vector<int> v;
    float sum = 0;
    for (int i = 0; i < n; i++)
    {
        int x;
        cin >> x;
        sum += x;
        v.push_back(sum);
    }
    find(v, sum, 0, v.size() - 1, 0);
    cout << f << endl;
    f = 0;
}
int main()
{
    int t;
    cin >> t;
    while (t--)
        testcase();
}