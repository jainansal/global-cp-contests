// https://icpc.codedrills.io/contests/icpc-mathura-kanpur-2022-regional-round/problems/gotta-catch-em-all

#include<bits/stdc++.h>
using namespace std;
#define ll long long

// TC - O(nlogn), SC - O(n)
void solution()
{
    ll n;
    cin>>n;
    vector<ll> alice(n), bob(n);
    for(auto &i:alice) cin>>i;
    for(auto &i:bob) cin>>i;
    sort(alice.begin(), alice.end());
    sort(bob.begin(), bob.end());

    ll i=0, j=0;
    while(i<n && j<n)
    {
        if(alice[i]<bob[j])
        {
            i++;
        }
        j++;
    }
    cout<<n-i;
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int test_cases;
    cin>>test_cases;
    for(int i=1; i<=test_cases; i++)
    {
        cout<<"Case "<<i<<": ";
        solution();
        cout<<endl;
    }
}