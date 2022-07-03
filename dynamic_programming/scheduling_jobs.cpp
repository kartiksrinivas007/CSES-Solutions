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
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); 
    ll n;
    cin>>n;

    vector<tuple<ll,ll,ll>>projects(n);
    for(int i =0; i<n; i++){
        cin>>get<0>(projects[i])>>get<1>(projects[i])>>get<2>(projects[i]);
    }
    vector<ll>dp(n,0);
    sort(projects.begin(), projects.end(), [](const tuple<ll,ll,ll>&a, const tuple<ll,ll,ll>&b){
        return get<0>(a) < get<0>(b);
    });
    //dp(j) is the max award I can obtain by using the jobs from j to n - 1 ( inclusive of j and n - 1)
    //this is interval scheduling but the greedy solution has been removed (thanks to the prices !) !
    //branch on selection or rejection of the job 
    for (int i =n - 1; i>= 0; i--){
        if( i == n -1 ){
            dp[i] = get<2>(projects[i]);
            continue;
        }
        else{
            ll index_special = -1;
            for (int j  = i + 1 ; j<n; j++){
                if(get<0>(projects[j]) > get<1>(projects[i])){
                    index_special = j;
                    break;
                }
            }
            if(index_special != - 1){
                dp[i] = max(dp[i+1], get<2>(projects[i]) + dp[index_special]);
            }
            else{
                dp[i] = max(dp[i+1],get<2>(projects[i]));
            }
            
        }
    }
    cout<<dp[0]<<endl;
    return 0;
}