#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define MOD 1000000007
#define N 1000002
bool isgreaterthanzero(ll input){
    if(input >= 0){
        return true;
    }
    else{
        return false;
    }
}
long long binpowmod(long long base, long long exp, long long mod){
    if(exp == 0){
        return 1;
    }
    if(exp == 1){
        return base;
    }
    else if(exp%2 == 0){
        return (binpowmod(base, exp/2, mod)%mod*binpowmod(base, exp/2, mod)%mod)%mod;
    }
    else{
        return (binpowmod(base, exp-1, mod)%mod*base)%mod;
    }
}
int main(){
    ll n,m;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    vector<vector<ll>>dp(N+1,vector<ll>(2));
    // 0 is vertical and 1 is (no - vertical line)
    dp[0][0] = 0;
    dp[0][1] = 0;
    dp[1][0] = 1;
    dp[1][1] = 1;
    for(int i=2; i<=N; i++){
        dp[i][0] = ((dp[i-1][0]*4)%MOD + dp[i-1][1])%MOD;
        dp[i][1] = ((dp[i-1][1]*2)%MOD + dp[i-1][0])%MOD;
    }
    cin>>m;     
    //use the query approach !!!
    while (m --){
        cin>>n;
        cout<<((dp[n][0]) + (dp[n][1]))%MOD<<endl;
        //dp[i][j] = num of arrangements of height = i and  ending with type j block
}
 return 0;
}