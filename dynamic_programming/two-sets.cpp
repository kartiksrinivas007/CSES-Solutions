#include<bits/stdc++.h>
typedef long long int ll;
using namespace std;
#define MOD 1000000007
#define MAXSUM (500*(500 + 1)/2 )+ 1
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
    cout<<""<<endl;
    ll sum = 0;
    vector<ll>inp(n,0);
    // cout<<MAXSUM<<endl;
    for( int i =1; i<=n; i++){
        inp[i] = i;
        sum = sum + inp[i];
    }
    vector<vector<ll>> dp(n+1,vector<ll>(MAXSUM,0));
    if(sum % 2 == 1){
        cout<<0<<endl;
    }
    //0 - 1 Knapsack
    // a 0 -1 knapsack cheks the possibility of a particular thing happening ! in this case it was about forming the sum!
    //dp[i][x] = true if its possible to form the sum x using the first i coins !
    // a copy of the NP complete problem that deals with this! 
    else{
         for (int i = 0; i<=n; i++){
            // cout<<"fine till"<<i<<endl;
            for (int x = 0; x <MAXSUM ; x++){
                if (i == 0 && x != 0){
                    dp[i][x] = 0;
                }
                else if (i==0 && x ==0){
                    dp[i][x] = 1;
                }
                else{
                    if(x >= inp[i-1]){
                        dp[i][x] = (dp[i-1][x-inp[i-1]] + dp[i-1][x])%MOD;
                    }
                    else{
                        dp[i][x] = dp[i-1][x];
                    }
                }
            }
        }
        // cout<<dp[n][sum/2]/2;
        cout<<"\n";
    }
    vector<vector<ll>>().swap(dp);
    return 0;
}