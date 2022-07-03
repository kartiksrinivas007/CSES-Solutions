#include<bits/stdc++.h>
using namespace std;


#define ii pair<long long int,long long int>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define MAXN 600 //if this was larger that much space would nto be available !

typedef long long int ll;

vector<vector<pair<ll,ll>>>adj(MAXN);
vector<vector<ll>>weights(MAXN, vector<ll>(MAXN,LLONG_MAX));
vector<vector<vector<ll>>>dp(MAXN, vector<vector<ll>>(MAXN, vector<ll>(MAXN,LLONG_MAX)));

void FW_apsp(ll n, ll m){
    for (int k =0; k<= n; k++){
        for(int i =1; i<=n ; i++){
           for (int j = 1; j<=n; j++){
                if(i == j){
                    dp[i][j][k] = 0;
                }
                else if(k==0){
                    // if( i == 1 && j == 2){
                    //     cout<<"weights = "<<weights[i][j]<<endl;
                    // }
                    if(weights[i][j] != LLONG_MAX){
                        dp[i][j][k] = weights[i][j];
                        // cout<<"setting edge weight for dp["<<i<<"]["<<j<<"]["<<k<<"] to "<<weights[i][j]<<endl;
                    }
                    else{
                        dp[i][j][k] = LLONG_MAX;
                    }
                }
                else{
                    dp[i][j][k] = dp[i][j][k-1];
                    if(dp[i][k][k-1] != LLONG_MAX && dp[k][j][k-1] != LLONG_MAX){
                        dp[i][j][k] = min(dp[i][j][k], dp[i][k][k-1] + dp[k][j][k-1]);
                    }

                }
           }

        }
    }

}


int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ll n, m,q;
    ll a, b, w;
    cin>>n>>m>>q;

    for (int i =0; i< m; i++){
        cin>>a>>b>>w;
        adj[a].pb(mp(b,w));
        adj[b].pb(mp(a,w));
        weights[a][b] = w;
        weights[b][a] = w;
    }

     FW_apsp(n, m);

    for (int i = 1; i<=q; i++){
        ll x, y;
        cin>>x>>y;
        if(dp[x][y][n] == LLONG_MAX){
            cout<<"-1"<<endl;
        }
        else{
            cout<<dp[x][y][n]<<endl;
        }
    }
    
   return 0;

   
}