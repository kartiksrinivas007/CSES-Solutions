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
    cin>>n>>m;
    vector<int>x(n);
    for (int &k :x){
        cin>>k;
    }
    vector<vector<int>>dp(n,vector<int>(m+1,0));
for (int i = 0 ; i<n; i++){
    for (int v = 1; v<=m; v++){
        if(i == 0){
            if(x[i] == 0){
                dp[i][v] = 1;
            }
            else if(v == x[i] && x[i] != 0 ){
                dp[i][v] = 1;
            }
            else{
                dp[i][v] = 0;
            }
        }
        else{
            if (x[i] == 0){
                dp[i][v] = ((dp[i-1][v]%MOD+ dp[i-1][v-1]%MOD)%MOD + dp[i-1][v+1]%MOD)%MOD;
            }
            else if(v == x[i] && x[i] != 0){
                 dp[i][v] = ((dp[i-1][v]%MOD+ dp[i-1][v-1]%MOD)%MOD + dp[i-1][v+1]%MOD)%MOD;
            }
            else if(v != x[i]){
                dp[i][v] = 0;
            }
        }
    }
}
ll sm =0;
    for (auto x: dp[n-1]){
        sm = (sm%MOD + x%MOD)%MOD;
    }
    cout<<sm<<endl;
    return 0;
}