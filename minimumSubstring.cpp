#include <bits/stdc++.h>
using namespace std;

int minWindow(string S, string T)
{
    int s = S.size();
    int t = T.size();

    int dp[s][t];
    memset(dp, -1, sizeof(dp));

    // initialization of first column
    for (int i = 0; i < s; i++)
    {
        if (S[i] == T[0])
            dp[i][0] = i;
        else if (i != 0)
            dp[i][0] = dp[i - 1][0];
    }

    for (int i = 1; i < s; i++)
    {
        for (int j = 1; j < t; j++)
        {
            if (S[i] == T[j])
            {
                dp[i][j] = dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }

    int ans = INT_MAX;
    int flag = 0;
    for (int i = 0; i < s; i++)
    {

        if (dp[i][t - 1] != -1)
        {
            flag = 1;
            int length = i - dp[i][t - 1] + 1;
            ans = min(ans, length);
        }
    }
    if (!flag)
    {
        return 0;
    }

    return ans;
}

int main()
{
    string s, t;
    cin >> s;
    t = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    cout << minWindow(s, t) << endl;
    return 0;
}