#include <bits/stdc++.h>
using namespace std;

int main()
{
    int n;
    cin >> n;
    int pt[n], tt[4 * n];

    for (int i = 0; i < n; i++)
    {
        cin >> pt[i];
    }
    for (int i = 0; i < 4 * n; i++)
    {
        cin >> tt[i];
    }

    sort(pt, pt + n);
    sort(tt, tt + 4 * n, greater<int>());

    int ans = 0;
    for (int i = 0; i < n; i++)
    {
        ans = max(ans, pt[i] + tt[4 * i]);
    }
    cout << ans;
    return 0;
}