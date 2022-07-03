#include<bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define f first
#define s second
#define mp make_pair
#define pb push_back

#define MAXN 100001
vector<vector<int>> adj(MAXN);
vector<int>vis(MAXN,0);
vector<int>team(MAXN);

void bfs_bipart(int vertex){
    queue<int>q;
    q.push(vertex);
    vis[vertex] = 1;
    team[vertex] = 1;
    while(!q.empty()){
        int p = q.front();
        q.pop();
        for(auto x: adj[p]){
            if(!vis[x]){
                q.push(x);
                vis[x]=1;
                team[x] = (team[p]==1)?2:1;
            }
            else{
                if(team[x] == team[p]){
                    cout<<"IMPOSSIBLE"<<endl;
                    return;
                }
                else {
                    continue;
                }
            }
        }
    }
}

//disconnected graph?!
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
    for(int i=1; i<=n;i++){
        if(!vis[i]){
            bfs_bipart(i);
        }
    }
    for (int i=1; i<=n; i++){
        cout<<team[i]<<" ";
    }
    cout<<endl;
    return 0;
}