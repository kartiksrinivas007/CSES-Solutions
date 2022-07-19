#include<bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define f first
#define s second
#define mp make_pair
#define pb push_back
typedef long long int ll;
#define MAXN 100002
vector<vector<pair<int, int>>> adj(MAXN);
vector<int>vis(MAXN,0);

// do a mst algorithm
priority_queue<ii, vector<ii>, greater<ii>>pq;
ll total_cost = 0;
void mst(ll vertex){
	pq.push(mp(0, vertex));
	while(!pq.empty()){
		ii popped = pq.top();
		pq.pop();
		//very important and repititve msitake is that its not abo9ut checking insidem oyu need to check outside for stray copies that are sent 
		//into the priority queue through other edges, always check outside also ( for dijkstra and for mst both!)
		if(vis[popped.s]){
			continue;
		}
		else{
			//cout<<"I have popped"<<popped.s<<endl;
			vis[popped.s] = 1;
			total_cost += popped.f;
			for (auto v : adj[popped.s]){
				if(!vis[v.f]){
					pq.push(mp(v.s, v.f));
				}
			}
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
        cin>>a>>b>>c;
        adj[a].pb({b,c});
        adj[b].pb({a,c});
    }
    mst(1);
    for (int i =1 ; i<=n ; i++){
		if(!vis[i]){
			cout<<"IMPOSSIBLE"<<endl;
			return 0;
		}
	}
	cout<<total_cost<<endl;
	return 0;
}
