// Created by minhtt
#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define name "a"
#define sz size()
#define ff first
#define ss second
typedef pair <int, int> ii;
const ll maxn = 2e5 + 7, mod = 1e9 + 7, base = 311, oo = 1e18;
int t[10], cur[10], ok[10];
ll ans = oo;
string s;
vector < int > a[10];
ll check()
{
    int tmp[12];
    ll res = 0;
    if (ok[2] == 2 && ok[5] == 2 && ok[7] == 1 && ok[9] == 2)
    {
        int tm = 1;
        tm ++;
    }
    for (int i = 1; i <= 9; ++i)
    {
        res += ok[i] * t[i];
        tmp[i] = cur[i];
    }
    for (int i = 1; i <= 9; ++i)
    {
        if (ok[i] > 0)
            for (auto j: a[i])
            {
                tmp[j] += ok[i];
                tmp[j] %= 3;
            }
    }
    for (int i = 1; i <= 9; ++i)
        if (tmp[i] != 1)
            return oo;

    return res;
}
void Try(int i)
{
    if (i > 9)
    {
        ans = min(ans, check());
        return;
    }
    for (int j = 0; j <= 2; ++j)
    {
        ok[i] = j;
        Try(i + 1);
        ok[i] = 0;
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
//    freopen(name".inp", "r", stdin);
    //freopen(name".out", "w", stdout);
    for (int i = 1; i <= 9; ++i)
    {
        cin >> t[i] >> s;
        for (auto j: s)
            a[i].push_back(int(j - '0'));
    }
    cin >> s;
    for (int i = 0; i < 9; ++i)
    {
        if (s[i] == 'D')
            cur[i+1] = 0;
        else if (s[i] == 'X')
            cur[i+1] = 1;
        else
            cur[i+1] = 2;
    }
    Try(1);
    if (ans == oo)
        cout << -1;
    else
        cout << ans;
    return 0;
}