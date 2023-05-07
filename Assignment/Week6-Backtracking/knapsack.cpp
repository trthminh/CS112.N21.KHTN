#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define name "a"
#define sz size()
#define ff first
#define ss second
typedef pair <int, int> ii;
const ll maxn = 23, mod = 1e9 + 7, base = 311, oo = 1e18;
int n, w[maxn], v[maxn], W, res;
void Try(int i, int sum_weight, int sum_values)
{
    //considered all cases
    if (i > n)
    {
        // update result
        res = max(res, sum_values);
        return;
    }
    // j = 0 -> don't choose item i
    // j = 1 -> choose item i
    for (int j = 0; j <= 1; ++j)
    {
        ok[i] = j;
        // if current sum of weights is out of capacity of knapsack
        // -> don't need to go far
        if (sum_weight + w[i] * j <= W)
            Try(i + 1, sum_weight + w[i] * j, sum_values + v[i] * j);
        ok[i] = 0;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    //freopen(name".inp", "r", stdin);
    //freopen(name".out", "w", stdout);
    // Number of items, capacity of knapsack
    cin >> n >> W;
    // weights of the items
    for (int i = 1; i <= n; ++i)
        cin >> w[i];
    // values of the items
    for (int i = 1; i <= n; ++i)
        cin >> v[i];
    // try item 1 with sum of current weight is 0
    Try(1, 0, 0);
    cout << res;
    return 0;
}
