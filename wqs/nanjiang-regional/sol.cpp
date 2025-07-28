#pragma GCC optimize("O3,unroll-loops,no-stack-protector")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

#define F first
#define S second
using namespace std;
typedef long long ll;

const int N = (int)3e5 + 5;

ll n, k, a[N], pre[N], dp[N], cnt[N];

inline ll cost(ll l, ll r)
{
     ll m = (l + r) / 2;
     return pre[r] - pre[m] - pre[((r - l) & 1) ? m : m - 1] + pre[l - 1];
}
inline pair<ll, ll> calc(ll i, ll j)
{
     return {dp[i] + cost(i + 1, j), -cnt[i] - 1};
}
pair<ll, ll> calc(ll x)
{
     struct Node
     {
          ll p, l, r;
     };
     deque<Node> dq;
     dp[0] = cnt[0] = 0;
     dq.push_back({0, 1, n});
     for (int i = 1; i <= n; ++i)
     {
          dp[i] = calc(dq.front().p, i).F + x, cnt[i] = cnt[dq.front().p] + 1;
          if (dq.front().r == i)
               dq.pop_front();
          else
               dq.front().l++;

          while (!dq.empty() && calc(i, dq.back().l) < calc(dq.back().p, dq.back().l))
               dq.pop_back();
          if (dq.empty())
               dq.push_back({i, i + 1, n});
          else
          {
               ll l = dq.back().l, r = dq.back().r;
               while (l < r)
               {
                    ll mid = r - (r - l) / 2;
                    if (calc(i, mid) < calc(dq.back().p, mid))
                         r = mid - 1;
                    else
                         l = mid;
               }
               dq.back().r = l;
               if (l != n)
                    dq.push_back({i, l + 1, n});
          }
     }
     return {cnt[n], dp[n]};
}

void init()
{
     cin >> n >> k;
     for (int i = 1; i <= n; ++i)
          cin >> a[i], pre[i] = pre[i - 1] + a[i];
}
void solve()
{
     ll l = 0, r = (ll)1e15, ans = -1;
     while (l <= r)
     {
          ll mid = l + (r - l) / 2;
          auto [cc, val] = calc(mid);
          if (cc >= k)
               l = mid + 1, ans = val - mid * k;
          else
               r = mid - 1;
     }
     cout << ans << '\n';
}

int main()
{
     ios_base::sync_with_stdio(0), cin.tie(0);
     init();
     solve();
}
