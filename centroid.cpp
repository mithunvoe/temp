#include <bits/stdc++.h>
// #include <ext/pb_ds/assoc_container.hpp>
// #include <ext/pb_ds/tree_policy.hpp>
using namespace std;
// using namespace __gnu_pbds;
// #define ordered_set tree<int, null_type,less<int>, rb_tree_tag,tree_order_statistics_node_update>
// mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
#define gInput g[u].push_back(v), g[v].push_back(u);
#define int long long
#define pii pair<int, int>
#define tata return 0
#define all(v) v.begin(), v.end()
#define endl '\n'
#define gap ' '

const int M = 1e9 + 7, N = 100005;
vector<int> g[N], subTree(N), deleted(N);
vector<char> color(N);
// char s[] = {'A', 'B'};
int getSubtreeSize(int node = 1, int p = -1)
{
    subTree[node] = 1;
    for (auto &it : g[node])
    {
        if (it == p || deleted[it])
            continue;
        subTree[node] += getSubtreeSize(it, node);
    }
    return subTree[node];
}
int getCentroid(int node, int treeSize, int p = -1)
{
    for (auto &it : g[node])
    {
        if (it == p || deleted[it])
            continue;
        if (subTree[it] * 2 > treeSize)
            return getCentroid(it, treeSize, node);
    }
    return node;
}
void magic(int node = 1, char c = 'A')
{
    int centroid = getCentroid(node, getSubtreeSize(node));
    deleted[centroid] = 1;
    color[centroid] = c;
    for (auto &it : g[centroid])
    {
        if (!deleted[it])
        {
            magic(it, c + 1);
        }
    }
}

void kire()
{
    int n;
    cin >> n;
    for (int i = 0; i < n - 1; i++)
    {
        int u, v;
        cin >> u >> v;
        gInput;
    }
    magic();
    for (int i = 0; i < n; i++)
    {
        cout << color[i + 1] << gap;
    }
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    // cin >> t;

    for (int i = 1; i <= t; i++)
    {
        // cout<<"Case "<<i<<": ";
        kire();
    }

    tata;
}
