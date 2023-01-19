#include <bits/stdc++.h>
using namespace std;

void toh(int n, char s, char h, char d)
{
    if (n == 0){
        // cout<<s<<h<<d;
        return;}
    toh(n - 1, s, d, h);

    cout << "Moving ring " << n << " from " << s << " to " << d << endl;

    toh(n - 1, h, s, d);
}
int main()
{
    int n;
    cin >> n;
    toh(n, 's', 'h', 'd');
    return 0;
}