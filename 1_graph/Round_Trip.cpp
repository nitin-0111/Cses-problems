#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")
#include <bits/stdc++.h>

using namespace std;
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
#ifndef ONLINE_JUDGE
#include <D:\Coding_and_Web\debug.cpp>
#else
#define debug(x...)
#endif
#define IOS                           \
    ios_base::sync_with_stdio(false); \
    cin.tie(NULL);

#define ppb pop_back
#define pf push_front
#define ppf pop_front
#define all(v) v.begin(), v.end()
#define uniq(v) v.erase(unique(all(v)), v.end())
#define sz(x) (int)((x).size())
#define ll long long
#define eps 1e-6
#define mod 1000000007
#define pi (3.141592653589)
#define ull uint64_t
#define cmp [](const auto &l, const auto &r) { return l > r; }
#define fi first
#define se second
#define prDouble(x) cout << fixed << setprecision(10) << x
#define rep(i, a, b) for (int i = a; i < b; i++)
#define fr(a, b) for (int i = a; i < b; i++)
#define mem1(a) memset(a, -1, sizeof(a))
#define mem0(a) memset(a, 0, sizeof(a))
#define rrep(i, n) for (int i = n - 1; i >= 0; i--)

#define pb push_back
#define vi vector<int>
#define yes cout << "YES" << endl;
#define no cout << "NO" << endl;
template <class T>
using ordered_set = tree<T, null_type, less<T>,
                         rb_tree_tag, tree_order_statistics_node_update>;

#define int int64_t

int n, m;
int sv, ev;
unordered_map<int, vector<int>> mp;
vector<int> vis;
vi parent;

bool dfs(int u, int p)
{

    vis[u] = 1;
    parent[u] = p;
    for (auto v : mp[u])
    {
        if (v == p)
            continue;
        if (vis[v])
        {
            sv = v;
            ev = u;
            return true;
        }
        if (!vis[v])
        {
            if (dfs(v, u))
            {
                return true;
            }
        }
    }
    return false;
}

bool fun()
{
    for (int i = 1; i <= n; i++)
    {
        if (!vis[i])
        {
            if (dfs(i, -1))
            {
                return 1;
            }
        }
    }
    return false;
}

void solve(int _t)
{

    cin >> n >> m;
    while (m--)
    {
        int x, y;
        cin >> x >> y;
        mp[x].pb(y);
        mp[y].pb(x);
    }
    vis.assign(n+1,0);
    parent.assign(n+1,-1);
    if (fun())
    {
        vector<int> ans;
        ans.pb(sv);
        ans.pb(ev);
        debug(sv,ev);
        debug(parent);
        while (ev != sv)
        {
            ev = parent[ev];
            debug(ev);
            ans.pb(ev);
        }

        // ans.pb(ev);
        reverse(all(ans));
        cout << ans.size() << endl;
        for (auto x : ans)
            cout << x << " ";
        cout << endl;
    }
    else
    {
        cout << "IMPOSSIBLE" << endl;
    }
}

signed main()

{
    IOS
        uint32_t test_case = 1;
#ifndef ONLINE_JUDGE
    // freopen( "input.txt"  , "r"  , stdin);
    // freopen("output.txt","w",stdout);
#endif
    int __t = test_case;

    while (test_case--)
    {

        solve(__t - test_case);
    }
    return 0;
}