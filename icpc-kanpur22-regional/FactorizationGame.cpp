// https://codedrills.io/contests/icpc-mathura-kanpur-2022-regional-round/problems/factorization-game

#include<bits/stdc++.h>
using namespace std;
#define ll long long

vector<ll> primes;

void sieve(ll lim)
{
    vector<bool> is_prime(lim+1,1);
    for(ll i=2; i*i<=lim; i++)
    {
        if(is_prime[i])
        {
            for(ll j=i*i; j<=lim; j+=i)
            {
                is_prime[j]=0;
            }
        }
    }
    for(int i=2; i<=lim; i++)
    {
        if(is_prime[i]) primes.push_back(i);
    }
}

ll factorCount(ll num)
{
    if(num==1) return 1;
    ll ans = 0;
    ll real_num = num;
    for(auto x:primes)
    {
        if(x*x > real_num) break;
        while(!(num%x))
        {
            ans++;
            num/=x;
        }
    }
    if(num>1) ans++;
    return ans;
}

void solution()
{
    ll n;
    cin>>n;
    if(factorCount(n)%2) cout<<"Bob";
    else cout<<"Alice";
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    ll test_cases;
    cin>>test_cases;
    sieve(1e6);
    for(int i=1; i<=test_cases; i++)
    {
        cout<<"Case "<<i<<": ";
        solution();
        cout<<endl;
    }
}