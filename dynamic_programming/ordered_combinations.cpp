#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define MOD 1000000007
bool isgreaterthanzero(ll input){
    if(input >= 0){
        return true;
    }
    else{
        return false;
    }
}
int main(){
    ll n,m;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin>>m>>n;
    vector<ll>currency(m);
    for(int i=0; i<m; i++){
        cin>>currency[i];
    }
    sort(currency.begin(), currency.end());
    vector<ll>dp(n+1,0);
    dp[0] =1;
    for(auto y: currency){
        for(int i=0; i<=n; i++){
            if(isgreaterthanzero(i-y)){
                dp[i] = ((dp[i]%MOD) + (dp[i-y]%MOD))%MOD;
            }
            else{
                continue;
            }
        }
    }
    cout<<dp[n]<<endl;
    return 0;
}