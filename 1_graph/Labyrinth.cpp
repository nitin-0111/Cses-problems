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

char grid[1000][1000];
bool vis[1000][1000];
int previousStep[1000][1000];// for track of dirction of parent  

void solve(int _t)
{

    int n, m;
    cin >> n >> m;

    pair<int, int> begin, end; // cooridnate of starting and end grid;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'A')
            {
                begin = {i, j};
            }
            else if (grid[i][j] == 'B')
            {
                end = {i, j};
            }
        }
    }
    queue<pair<int, int>> q;
    /* we use  bfs  bcz
      1. shortest path required
      */

    int dx[4] = {-1, 0, 1, 0};
    int dy[4] = {0, 1, 0, -1};
    string stepDir = "URDL";

    q.push(begin);
    vis[begin.fi][begin.se] = 1;
    while (!q.empty())
    {
        pair<int, int> u = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            pair<int, int> v = {u.fi + dx[i], u.se + dy[i]};

            // check for valid

            if (v.fi < 0 || v.fi >= n || v.se < 0 || v.se >= m)
                continue;
            if (grid[v.fi][v.se] == '#' || vis[v.fi][v.se])
                continue;

            vis[v.fi][v.se] = 1;
            previousStep[v.fi][v.se] = i;
            q.push(v);
        }
    }

    if (vis[end.fi][end.se])
    {
        cout << "YES" << endl;

        vector<int> steps;
        while (end != begin)
        {
            int p = previousStep[end.fi][end.se]; 
            steps.pb(p);
            end = {end.fi - dx[p], end.se - dy[p]};
        }
        reverse(all(steps));
        cout << steps.size() << endl;
        for (auto c : steps)
        {
            cout << stepDir[c];
        }
        cout << endl;
    }
    else
        cout << "NO" << endl;
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