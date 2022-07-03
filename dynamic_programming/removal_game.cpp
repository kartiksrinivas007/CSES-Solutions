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
bool isValid(ll input , ll n){
    if (input >=0 && input <= n-1){
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
    ll sum = 0;
    vector<int>a(n,0);
    for( int i =0; i<n; i++){
        cin>>a[i];
        sum = sum + a[i];
    }
    vector<vector<ll>>dp(n,vector<ll>(n,0));
    vector<ll>optimal_choices;
    //let dp[i][j] represent the max number of points i can obtain by playing as the first player using the subarray i to j !
    //I will branch over the decision to choose the first or the last position !
    //turns out the approach actually uses the difference of the scores 
    //dp[i][j] =  max score difference between us both ...note that the sum of scores = sum of elements , so the difference needs 
    //be maximized 
    // dp[i][j] = 
    for (int i = n - 1; i>=0 ; i--){
        for (int j = 0; j <n; j++){
            if( i > j){
                dp[i][j] = 0;
            }
            if(i == j){
                dp[i][j] = a[i];
            }
            else if(i < j){
                dp[i][j] = 0;
                if(isValid(i+1,n)){
                   dp[i][j] = a[i]-dp[i+1][j];
                }
                if(isValid(j-1,n)){
                    dp[i][j] = max(dp[i][j],a[j]-dp[i][j-1]);
                }
            }    
           
        }
    }
    cout<<(dp[0][n-1] + sum)/2<<endl;
    // for (auto x: dp){
    //     for (auto y : x){
    //         cout<<y<<" ";
    //     }
    //     cout<<'\n';
    // }

    return 0;
}