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
    for( int i =0; i<n; i++){
        cin>>coins[i];
    }
    
    //0 - 1 Knapsack
    // a 0 -1 knapsack cheks the possibility of a particular thing happening ! in this case it was about forming the sum!
    //dp[i][x] = true if its possible to form the sum x using the first i coins !
    // a copy of the NP complete problem that deals with this! 
    #define MAXSUM 100001
    vector<vector<ll>>dp(n+1,vector<ll>(MAXSUM,0));
    for (int i = 0; i<=n; i++){
        for (int x = 0; x< MAXSUM ; x++){
             if ( i == 0 && x != 0){
                dp[i][x] = 0;
             }
             else if (i==0 && x ==0){
                dp[i][x] = 1;
             }
             else{
                if(dp[i-1][x] == 1){
                    dp[i][x] = 1;
                }
                else if(x >= coins[i-1]){
                    dp[i][x] = dp[i-1][x-coins[i-1]];
                }
                else{
                    dp[i][x] = 0;
                }
             }
        }
    }
    ll count = 0;
    for (int x = 1; x < MAXSUM; x++){
        if(dp[n][x] == 1){
            count ++;
        }
    }
    cout<<count<<endl;
    for (int x = 1; x < MAXSUM; x++){
        if(dp[n][x] == 1){
            cout<<x<<" ";
        }
    }
    cout<<"\n";
    return 0;
}