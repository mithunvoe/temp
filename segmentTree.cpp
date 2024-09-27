#include <bits/stdc++.h>
using namespace std;
#define int long long
#define tata return 0
#define all(v) v.begin(), v.end()
#define endl '\n'
#define gap ' '

const int M = 1e9 + 7;

struct segTree
{
    int n;
    vector<int> v, a;

    segTree(int _n, int _a[])
    {
        n = _n;
        a.assign(_a, _a + n);
        v.resize(4 * n);
        build(0, n - 1, 1);
    }
    void build(int tl, int tr, int node)
    {
        if (tl == tr)
            v[node] = a[tl];
        else
        {
            int mid = (tl + tr) / 2;
            build(tl, mid, 2 * node);
            build(mid + 1, tr, 2 * node + 1);
            v[node] = v[node * 2] + v[node * 2 + 1];
        }
    }
    int sum(int tl, int tr, int l, int r, int node)
    {
        if (l > r)
            return 0;
        if (l == tl && r == tr)
            return v[node];
        int mid = (tl + tr) / 2;
        return sum(tl, mid, l, min(r, mid), node * 2) + sum(mid + 1, tr, max(l, mid + 1), r, node * 2 + 1);
    }
    void update(int tl, int tr, int pos, int val, int node)
    {
        if (tl == tr)
            v[node] = val;
        else
        {
            int mid = (tl + tr) / 2;
            if (pos <= mid)
                update(tl, mid, pos, val, node * 2);
            else
                update(mid + 1, tr, pos, val, node * 2 + 1);
            v[node] = v[node * 2] + v[node * 2 + 1];
        }
    }
};
void kire()
{
    int n;
    cin >> n;
    int a[n];
    for (auto &it : a)
        cin >> it;
    segTree tree(n, a);
    cout << tree.sum(0, n - 1, 0, 3, 1) << endl;
    tree.update(0, n - 1, 2, 12, 1);
    cout << tree.sum(0, n - 1, 2, 2, 1) << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t = 1;

    for (int i = 1; i <= t; i++)
    {

        kire();
    }

    tata;
}