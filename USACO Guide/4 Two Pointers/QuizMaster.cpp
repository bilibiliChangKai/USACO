#include <iostream>
#include <algorithm>
#include <cstring>
#include <vector>
using namespace std;
const int N = 1e5 + 2;
// d[j]的含义是j的小于m的因数有哪些
// 预处理操作
vector<int> d[N];
int n, m;
int a[N], cnt[N], s = 0;
void init()
{
    for (int i = 1; i <= 1e5; i++)
        for (int j = i; j <= 1e5; j += i)
            d[j].push_back(i);
}
void solve()
{
    memset(cnt, 0, sizeof(cnt));
    s = 0;
    cin >> n >> m;
    for (int i = 1; i <= n; i++)
        scanf("%d", &a[i]);
    sort(a + 1, a + n + 1);
    int ans = 1e9;
    for (int l = 1, r = 1; r <= n; r++)
    {
        for (auto x : d[a[r]])
        {
            if (x > m)
                break;
            if (cnt[x] == 0)
                s++;
            cnt[x]++;
        }
        while (s == m)
        {
            ans = min(ans, a[r] - a[l]);
            for (auto x : d[a[l]])
            {
                if (x > m)
                    break;
                if (cnt[x] > 0)
                    cnt[x]--;
                if (cnt[x] == 0)
                    s--;
            }
            l++;
        }
    }
    if (ans >= 1e9)
        cout << -1 << endl;
    else
        cout << ans << endl;
}
int main()
{
    init();
    int t;
    cin >> t;
    while (t--)
        solve();
    return 0;
}