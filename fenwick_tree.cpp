#include <bits/stdc++.h>
using namespace std;
int bit[200005];
void update(int i, int delta)
{
    i++; // hack to allow 0-based indexing in fenwick tree
    for (; i <= n; i += i & -i)
        bit[i] += delta;
}

int query(int l, int r)
{
    r++;
    int sum = 0;

    for (; r > 0; r -= r & -r)
        sum += bit[r];
    for (; l > 0; l -= l & -l)
        sum -= bit[l];
    return sum;
}