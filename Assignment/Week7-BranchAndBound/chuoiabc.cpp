#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define name "a"
#define ff first
#define ss second
typedef pair <int, int> ii;
const ll maxn = 2e5 + 7, mod = 1e9 + 7, base = 311, oo = 1e18;
string s, ans="";
ll res = oo;
int n;
bool cmpstr(int s1, int e1, int s2, int e2)
{
    if (s2 < 0)
        return false;
    int j = s2;
    for (int i = s1; i <= e1; ++i)
    {
        if (s[i] != s[j])
            return false;
        ++j;
    }
    return true;
}
bool check()
{
    int sz = s.size();
    int en = sz - 1;
    for (int i = 1; i <= sz/2; ++i) // len
    {
        if (s.substr(en-2*i+1, i) == s.substr(en-i+1, i))
//        if (cmpstr(en - 2*i + 1, en - i, en - i + 1, en))
            return false;
    }
    return true;
}
void thu(int i, int nC)
{
    if (!check())
        return;
    if (i > n)
    {
        if (nC < res)
        {
            res = nC;
            ans = s;
        }
        return;
    }
    for (int j = 'A'; j <= 'C'; ++j)
    {
        if (i > 1 && s[s.size()-1] == j)
            continue;
        if (ans.size() > 0 && nC + (j == 'C') + (n - i - 1) / 4 >= res)
            continue;

        s.push_back(j);
        //if (check())
            thu(i + 1, nC + (j == 'C'));
        s.pop_back();
    }
}
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
//    freopen(name".inp", "r", stdin);
    //freopen(name".out", "w", stdout);
    cin >> n;
    thu(1, 0);
    for (auto i:ans)
        cout << i;
    return 0;
}