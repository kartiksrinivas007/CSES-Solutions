#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
const ll INF  = 1e17;
#define endl '\n'
int main()
{
    ll n; 
    cin>>n;
    ll sum = 0;
    vector<ll>p(n, 0);
    for (auto &i : p){
        cin>>i;
        sum+=i;
    }
    ll min_ans = INF;
    for (ll mask  = 1; mask < (1 << n); mask ++){
        ll sum_subset = 0;
        for (ll i = 0; i<n; i++){
            if(mask & (1 <<i)){
                sum_subset += p[i];
            }
        }
        ll sum_remaining = sum - sum_subset;
        min_ans = min(min_ans, abs(sum_remaining - sum_subset));
    }
    cout<<min_ans<<endl;
    return 0;
}