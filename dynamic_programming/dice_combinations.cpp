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
    ll n;
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    cin>>n;
    vector<ll>dp(n+1);
    dp[0] = 1;
    for (int i = 1; i<=n; i++){
       for(int j =1; j<=6; j++){
        if(isgreaterthanzero(i-j)){
            dp[i] = ((dp[i]%MOD) + (dp[i-j]%MOD))%MOD;
        }
        else{
            break;
        }
       }
    }
    cout<<dp[n]<<endl;
    return 0;
}