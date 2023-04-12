#include <bits/stdc++.h>
using namespace std;
#define ll long long

vector<bool> is_prime;
vector<ll> all_primes;

void primes(ll lim)
{
    vector<bool> is_Prime(lim + 1, 1);
    is_prime = is_Prime;
    for (int i = 2; i * i <= lim; i++)
    {
        if (is_prime[i])
        {
            all_primes.push_back(i);
            for (int j = i * i; j <= lim; j += i)
            {
                is_prime[j] = 0;
            }
        }
    }
}

ll factors(ll num)
{
    cout<<num<<":";
    ll ans = 0;
    for(auto i:all_primes)
    {
        if(i>num) break;
        while(!(num%i))
        {
            ans++;
            num/=i;
        }
    }
    if(num>1) ans++;
    cout<<ans<<endl;
    return ans;
}

ll maxOps(vector<ll> &nodes, vector<vector<ll>> &edges)
{
    ll ans = 0;
    ll n = edges.size();
    
    for (auto i : edges)
    {
        ll num1 = nodes[i[0] - 1], num2 = nodes[i[1] - 1];
        cout<<num1<<" "<<num2<<endl;
        ll g = __gcd(num1, num2);
        ans += factors(g);
        num1 /= g, num2 /= g;
        nodes[i[0] - 1] = num1, nodes[i[1] - 1] = num2;
    }
    return ans;
}

void solution()
{
    ll n;
    cin >> n;
    vector<ll> nodes(n);
    for (auto &i : nodes)
        cin >> i;
    vector<vector<ll>> edges(n - 1);
    for (int i = 0; i < (n - 1); i++)
    {
        ll x, y;
        cin >> x >> y;
        edges[i] = {x, y};
    }
    // for(int i=2; i<=20; i++) cout<<is_prime[i]<<" ";
    cout << maxOps(nodes, edges);
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    primes(1e7);
    int test_cases;
    cin >> test_cases;
    for (int i = 1; i <= test_cases; i++)
    {
        cout << "Case " << i << ": ";
        solution();
        cout << endl;
    }
}