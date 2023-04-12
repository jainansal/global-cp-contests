// https://codedrills.io/contests/icpc-mathura-kanpur-2022-regional-round/problems/little-seherish-and-tree

#include <bits/stdc++.h>
using namespace std;
#define ll long long

ll factors(ll num)
{
    ll ans = 0;
    for (ll i = 2; i * i <= num; i++)
    {
        while (!(num % i))
        {
            ans++;
            num /= i;
        }
    }
    if (num > 1)
        ans++;
    return ans;
}

ll maxOps(vector<ll> &nodes, vector<set<ll>> &adj)
{
    ll n = nodes.size();
    ll ans = 0;
    while (true)
    {
        vector<ll> node_list;
        for (int i = 1; i <= n; i++)
        {
            if (adj[i].size() == 1)
                node_list.push_back(i);
        }
        if (!node_list.size())
            break;
        for (auto x : node_list)
        {
            if (!adj[x].size())
                continue;
            ll node1 = x, node2 = *adj[x].begin();
            ll g = __gcd(nodes[node1], nodes[node2]);
            adj[node1].clear();
            adj[node2].erase(node1);
            ans += factors(g);
            nodes[node1] /= g, nodes[node2] /= g;
        }
    }
    return ans;
}

void solution()
{
    ll n;
    cin >> n;
    vector<ll> nodes(n + 1);
    for (int i = 1; i <= n; i++)
        cin >> nodes[i];
    vector<set<ll>> adj(n + 1);
    for (int i = 1; i < n; i++)
    {
        ll x, y;
        cin >> x >> y;
        adj[x].insert(y);
        adj[y].insert(x);
    }
    cout << maxOps(nodes, adj);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test_cases;
    cin >> test_cases;
    for (int i = 1; i <= test_cases; i++)
    {
        cout << "Case " << i << ": ";
        solution();
        cout << endl;
    }
}