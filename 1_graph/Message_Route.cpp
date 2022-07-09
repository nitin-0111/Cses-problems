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
unordered_map<int, list<int>> l;
#define T int
void shortpath(T src, T e)
{
    map<T, int> dist;
    queue<T> q;
    // traversing the bfs  way
    for (auto node_pair : l)
    {
        T node = node_pair.first;
        dist[node] = INT_MAX;
    }
    // intialisizing the scr ->0 and all other with infinite

    q.push(src);
    map<int,int> path;
    path[src]=src;
    dist[src] = 0;
    while (!q.empty())
    {
        T node = q.front();
        q.pop();
        for (T nbr : l[node])
        {
            if (dist[nbr] == INT_MAX)
            {
                q.push(nbr);
                dist[nbr] = dist[node] + 1;
               path[nbr]=node;
            }
        }
    }
    if(dist[e]==INT_MAX)
    {
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        cout<<dist[e]<<endl;
        vector<int> ans;
        ans.pb(e);
        while(e!=src)
        {
           e=path[e];
           ans.pb(e);
        }
        reverse(all(ans));
        for(auto x: ans)
        {
            cout<<x<<" ";
        }
        cout<<endl;

    }
}

void solve(int _t)
{
    int n,m;
    cin>>n>>m;
    while(m--)
    {
        int x,y;
        cin>>x>>y;
        l[x].pb(y);
        l[y].pb(x);
    }
    shortpath(1,n);
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