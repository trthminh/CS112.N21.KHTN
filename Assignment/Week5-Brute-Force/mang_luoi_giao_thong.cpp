#include <iostream>
#include <vector>
#include <queue>
#define MAX 100000
#define ll long long
using namespace std;
vector <int> V[MAX];
queue <int > q;
int n,m,x,y,od, mark[MAX];
ll S,res;

void input()
{
    cin >> n >> m; //m dinh n cau
    for (int i=1; i<=m; i++)
    {
        cin >> x >> y;
        V[x].push_back(y);
        V[y].push_back(x);
    }
}

void BFS(int j)
{
    q.push(j);
    mark[j] = od;
    while (!q.empty())
    {
        int a = q.front();
        q.pop();
        for (int u:V[a])
        {
            if (mark[u]==0)
            {
                q.push(u);
                mark[u] = od;
            }
        }
    }
}
int main()
{
    input();
    for (int i=1; i<=n; i++)
        if (mark[i] == 0)
        {
            od++;
            BFS(i);
        }

    int cnt[od+1] = {}; 
    for (int i=1; i<=n; i++)
        cnt[mark[i]]++;
    for (int i=2; i<=od; i++)    //Res4 = Sum(Cnt1->Cnt3)*Cnt4
    {
        S += cnt[i-1];
        res += S*cnt[i];
    }
    cout << res;

}