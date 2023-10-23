int dp[101][102];
int cutRod(vector<int> &price, int n)
{
    //BASE
    for(int i=0;i<=n;i++)
    {
        dp[0][i]=i*price[0];
    }

    for(int ind =1;ind<n;ind++)
    {
                for (int j = 0; j <= n; j++)
                 {
                  int not_take = dp[ind - 1][j];
                  int take = -1e8;
                  int rodlen = ind + 1;
                  if (rodlen <= j)
                    take = price[ind] + dp[ind][j - rodlen];
                  dp[ind][j] = max(take, not_take);
                }
        }
        return dp[n-1][n];
}
