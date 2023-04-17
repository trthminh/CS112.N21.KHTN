#include <iostream>
#include <algorithm>
#define MAX 10000
using namespace std;
int n,m,a[MAX];
int cnt=1;
int BS(int l, int h) //1,5
{
    int res;
    while (l<=h) //1<=5 //1<=2
    {
        int mid = l + (h-l)/2; //mid = 3 //mid = 1
//        for (int i=0; i<n; i++)
//            if (a[i+1] - a[i] > 2*mid)
//                cnt++; //cnt = 2 //cnt = 3

        int it = 0, i = 1, cnt = 1;
        while (i<n)
        {
            if (a[i] - a[it] > 2*mid)
            {
                it = i;
                cnt++;
            }

            i++;
        }
        if (cnt <= m)
        {
            h=mid-1; //h = mid-1 = 2
            res = mid;
        }
        else l=mid+1; //l = mid+1 = 2
        cnt = 1;
    }
    return res;
}

int main()
{
    cin >> n >> m;
    for (int i=0; i<n; i++)
        cin >> a[i];
    //l=1; h=(a[max] - a[min] + 1)/2
    sort(a,a+n);
    cout << BS(1, (a[n-1]-a[0]+1)/2);
}