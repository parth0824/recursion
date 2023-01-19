#include <bits/stdc++.h>
using namespace std;
int ans = 0;

void printPermutaion(vector<bool> nums, int ind, int p)
{
    if (ind < p)
    {
        ans++;
    }
    for (int i = 0; i < nums.size(); i++)
    {
        if (nums[i] == 0 && (((p % (i + 1)) == 0) || (((i + 1) % (p)) == 0)))
        {
            nums[i] = 1;
            printPermutaion(nums, ind, 1 + p);
            nums[i] = 0;
        }
    }
}
void countArrangement(int n)
{

    vector<bool> nums;
    for (int i = 0; i < n; i++)
        nums.push_back(0);
    printPermutaion(nums, n, 1);
}
int main()
{
    int n;
    cin >> n;
    countArrangement(n);
    cout << ans;
    return 0;
}
