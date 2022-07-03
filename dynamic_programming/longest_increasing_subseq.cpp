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
    int n;
    cin>>n;
    vector<int>a(n,0);
    for (int i =0; i<n; i++){
        cin>>a[i];
    }
    vector<ll>dp(n,0);
    //dp (j) = LIST of all the elements that can be formed using the first j elements of the array and ends at a(j)
    for(int j = 0; j< n; j++){
        if( j == 0){
            dp[j] = 1;
            continue;
        }
        dp[j] = 1;
        for(int i =0; i<j; i++){
            if(a[j] > a[i]){
                dp[j] = max(dp[j], 1 + dp[i]);
            }
            else {
                continue;
            }
        }
    }
    cout<<*max_element(dp.begin(), dp.end())<<endl;
    return 0;
}