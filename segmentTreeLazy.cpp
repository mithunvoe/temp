#include <bits/stdc++.h>
using namespace std;
#define int long long
#define tata return 0
#define all(v) v.begin(), v.end()
#define endl '\n'
#define gap ' '

const int M = 1e9 + 7;
struct segTreeL
{
    int n;
    vector<int> v, a;
    segTreeL(int _n, int _a[])
    {
        n = _n;
        v.resize(4 * n);
        a.assign(_a, _a + _n);
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
            v[node] = 0;
        }
    }
    int query(int tl, int tr, int pos, int node)
    {
        if (tl == tr)
            return v[node];
        else
        {
            int mid = (tl + tr) / 2;
            if (pos <= mid)
                return v[node] + query(tl, mid, pos, 2 * node);
            else
                return v[node] + query(mid + 1, tr, pos, 2 * node+1);
        }
    }
    void update(int tl, int tr, int l, int r, int val, int node)
    {
        if (l > r)
            return;
        if (l == tl && r == tr)
        {
            v[node] += val;
            return;
        }
        int mid = (tl + tr) / 2;

        update(tl, mid, l, min(r, mid), val, 2 * node);
        update(mid + 1, tr, max(l, mid + 1), r, val, 2 * node + 1);
    }
};

void kire()
{
    int n;
    cin >> n;
    int a[n];
    for (auto &it : a)
        cin >> it;

    segTreeL tree(n, a);

    tree.update(0, n - 1, 2, n - 1, 3, 1);
    cout << tree.query(0, n - 1, 3, 1) << endl;
    cout << tree.query(0, n - 1, 4, 1) << endl;
}

int32_t main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);
    int t = 1;
    // cin>>t;

    for (int i = 1; i <= t; i++)
    {
        // cout<<"Case "<<i<<": ";
        kire();
    }

    tata;
}