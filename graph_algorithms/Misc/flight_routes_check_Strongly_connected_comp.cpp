#include<bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define f first
#define s second
#define mp make_pair
#define pb push_back
typedef long long int ll;
#define MAXN 100002
vector<vector<int>> adj(MAXN);
vector<vector<int>>in_adj(MAXN); //this mantaint the in-elements
vector<int>vis(MAXN,0);

void dfs(vector<vector<int>>& adj, int vertex){
	vis[vertex] = 1;
	for (auto  v : adj[vertex]){
		if(!vis[v]){
			dfs(adj, v);
		}
	}
}
bool is_connected(vector<int>vis , int n){
	for (int i = 1; i<=n ; i++){
		if(!vis[i]){
			return false;
		}
	}
	return true;
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n, m;
    int a, b, c;
    cin>>n>>m;
    for(int i=0; i< m; i++){
        cin>>a>>b;
        adj[a].pb(b);
        in_adj[b].pb(a);
    }
    dfs(adj, 1);
    bool first = is_connected(vis, n);
	if(!first){
			for(int i = 1; i<=n; i++){
				if(!vis[i]){
					cout<<"NO"<<endl;
					cout<<1<<" "<<i<<endl;
				}
			}
	}
    fill(vis.begin(), vis.end(), 0 );
    dfs(in_adj, 1);
    bool second = is_connected(vis, n);
    if(!second){
			for(int i = 1; i<=n; i++){
				if(!vis[i]){
					cout<<"NO"<<endl;
					cout<<i<<" "<<1<<endl;
				}
			}
	}
    if( first && second){
		cout<<"YES"<<endl;
	}
    
	return 0;
}
