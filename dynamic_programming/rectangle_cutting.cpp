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
    #ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
    #endif
    ll n;
    cin>>n;
    vector<int>coins(n,0);
    for (int &k :coins){
        cin>>k;
    }
    //probably try to use a c++ set to insert the possible sums !
    vector<ll>dp(n+1,0);
    dp[0] = 0;
    vector<ll>hash(100001,0);
    for(int i = 1 ; i<=n; i++){
        dp[i] = dp[i-1];
        if(hash[coins[i-1]] == 0){
            dp[i] += 1;
            hash[coins[i-1]] = 1;
        }

          for (int j = 0; j<=i; j++){
                if(hash[coins[j] + coins[i-1]] == 0){
                        hash[coins[j] + coins[i-1]] = 1;
                        dp[i] = dp[i] + 1;
                }
                else{
                        continue;
                }
            
        }
        cout<<"Number of combinations from 1..."<<i<<"="<<dp[i]<<endl;
    }
    cout<<dp[n]<<endl;
    return 0;
}