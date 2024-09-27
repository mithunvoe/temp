class TreeAncestor
{
public:
    vector<vector<int>> dp;

    TreeAncestor(vector<int> &parent)
    {
        int n = parent.size();
        dp.resize(17, vector<int>(n, -1));

        for (int i = 0; i < n; i++)
            dp[0][i] = parent[i];

        for (int i = 1; i < 17; i++)
        {
            for (int j = 0; j < n; j++)
            {
                if (dp[i - 1][j] != -1)
                    dp[i][j] = dp[i - 1][dp[i - 1][j]];
            }
        }
    }

    int getKthAncestor(int node, int k)
    {
        for (int p = 0; p < 17; p++)
        {
            if (k & (1LL << p))
            {
                node = dp[p][node];
                if (node == -1)
                    break;
            }
        }
        return node;
    }
};