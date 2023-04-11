// https://icpc.codedrills.io/contests/icpc-mathura-kanpur-2022-regional-round/problems/marriage-vs-gym

#include <bits/stdc++.h>
using namespace std;
#define ll long long

bool isFeasible(vector<ll> &vec, long double y, ll m, ll k, ll c, ll n, ll l)
{
    long double cur = l;
    for (auto i : vec)
    {
        if (cur + i - n - y < c)
            return false;
        cur = cur + i - n - y;
    }
    return true;
}

void solution()
{
    ll m, k, c, n, l;
    cin >> m >> k >> c >> n >> l;
    vector<ll> vec(m);
    for (auto &i : vec)
        cin >> i;
    long double lo = 0, hi = 1e12, ans = -1;
    ll iterations = 100;
    while (lo <= hi && iterations--)
    {
        long double mid = (lo + hi) / 2;
        if (isFeasible(vec, mid, m, k, c, n, l))
        {
            lo = mid;
            ans = mid;
        }
        else
        {
            hi = mid;
        }
    }
    long double sum = l;
    for (auto i : vec)
    {
        sum = sum + i - lo - n;
    }

    if (sum <= k)
        cout << fixed << setprecision(6) << ans;
    else
        cout << -1;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test_cases;
    cin >> test_cases;
    while (test_cases--)
    {
        solution();
        cout << endl;
    }
}