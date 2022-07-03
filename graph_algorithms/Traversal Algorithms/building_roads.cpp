#include<bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define f first
#define s second
#define mp make_pair
#define pb push_back

#define MAXN 100000
vector<vector<int>> adj(MAXN);
vector<int>vis(MAXN,0);

void dfs(int vertex){
    vis[vertex]=1;
    for(int i=0;i<adj[vertex].size();i++){
        int v=adj[vertex][i];
        if(!vis[v]){
            dfs(v);
        }
    }
}
int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n, m;
    int a, b;
    cin>>n>>m;
    for(int i=0; i< m; i++){
        cin>>a>>b;
        adj[a].pb(b);
        adj[b].pb(a);
    }
    //graph has been made!
    vector<int>elements;
    int num_of_components=1;
    dfs(1);
    for(int i = 2; i<=n; i++){
        if(!vis[i]){
            dfs(i);
            elements.pb(i);
            num_of_components++;
        }
    }
    cout<<num_of_components-1<<endl;
    for (auto x: elements){
        cout<<1<<" "<<x<<endl;
    }
    return 0;
}