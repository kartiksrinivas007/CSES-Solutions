#include<bits/stdc++.h>

using namespace std;
typedef long long int ll ;
#define MAXN 1000000000
int main(){
    #ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

    ll n;
    cin>>n;
    ll count = 0;
    
    while(n > 1){
        count = count + (ll)(n/5);
        n = n/5;
    }
    cout<<count<<endl;
    return 0;
}