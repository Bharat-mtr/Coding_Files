#include <bits/stdc++.h>
using namespace std;

vector<int> LPS(string &pattern)
{
    int n = pattern.size();
    vector<int> lps(n);
    lps[0] = 0;

    for (int i = 1; i < n; i++)
    {
        int j = lps[i - 1];

        while (j > 0 && pattern[i] != pattern[j])
        {
            j = lps[j - 1];
        }

        if (pattern[i] == pattern[j])
        {
            j++;
        }
        lps[i] = j;
    }

    return lps;
}

int main()
{
    string text, pattern;
    cin >> text >> pattern;

    vector<int> lps = LPS(pattern);

    // for (auto &x : lps)
    // {
    //     cout << x << " ";
    // }

    int pos = -1;
    int i = 0, j = 0;
    int n = text.size();
    while (i < n)
    {
        if (text[i] == pattern[j])
        {
            i++;
            j++;
        }
        else
        {
            if (j != 0)
            {
                j = lps[j - 1];
            }
            else
            {
                i++;
            }
        }
        if (j == pattern.size())
        {
            pos = i - pattern.size();
            // break;
        }
    }
    cout << pos << endl;
}