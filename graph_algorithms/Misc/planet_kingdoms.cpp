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
vector<int>label(MAXN, -1);
vector<int>vis_2(MAXN,0);

void dfs(vector<vector<int>>& adj, int vertex, vector<int>&vis){
	vis[vertex] = 1;
	for (auto  v : adj[vertex]){
		if(!vis[v]){
			dfs(adj, v, vis);
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
    int a, b, c;
    cin>>n>>m;
    for(int i=0; i< m; i++){
        cin>>a>>b;
        adj[a].pb(b);
        in_adj[b].pb(a);
    }
    ll count = 1;
    for (int i = 1; i<=n ; i++){
		///1 - mark a bunch of guys (under visited ( say) )
		//then i need to go and mark a bucnh of guys under intersection ( my own )
		//then i will go and mark the members using label, label will hold onlty inersection members 
		//then i will go t the next non labelled element and do the same, i need to refill visisite dthough 
		if(label[i] == -1){
			dfs(adj, i, vis);
			dfs(in_adj,i, vis_2);
			for(int j = 1; j<=n ; j++){
				if(vis[j] && vis_2[j]){
					label[j] = count;
				}
			}
			count ++;
			fill(vis.begin(), vis.end(), 0);
			fill(vis_2.begin(), vis_2.end(),0);
		}
	}
	cout<<count - 1<<endl;
	for(int i =1; i<=n ;i++){
		cout<<label[i]<<" ";
	}
	cout<<endl;
	//dfs(adj, 1, vis);
	//for(int i =1; i<=n ; i++){
		//cout<<vis[i]<<endl;
	//}
	//dfs(in_adj, 1, vis_2);
	//cout<<"NOOOOOOOOOOOW"<<endl;
	//for(int i =1; i<=n ; i++){
		//cout<<vis_2[i]<<endl;
	//}
	
    
    
	return 0;
}
