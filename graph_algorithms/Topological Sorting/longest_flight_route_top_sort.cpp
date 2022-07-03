#include<bits/stdc++.h>
using namespace std;


#define ii pair<long long int,long long int>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define MAXN 100001 //if thsi was larger that much space would nto be available !
#define in :

typedef long long int ll;

const ll INF = 1e17;
const ll NINF = -INF;

vector<vector<ll>>adj(MAXN);
vector<ll>indegree(MAXN,0); //careful! 
vector<ll>top_sort;
vector<ll>vis(MAXN , 0);
vector<ll>max_dist(MAXN, NINF);
vector<ll>parent(MAXN, -1);


void topological_sort(ll n, vector<ll> &top_sort, vector<ll>indeg){
    queue<ll>zero_in_deg;
    for (int i =1; i<=n; i++){
        if (indeg[i] == 0){
            zero_in_deg.push(i);
        }
    }
    while(!zero_in_deg.empty()){
        ll popped = zero_in_deg.front();
        top_sort.push_back(popped);
        zero_in_deg.pop();
        for(auto x: adj[popped]){
            indeg[x] -- ;
            if(indeg[x] == 0){
                zero_in_deg.push(x);
            }
        }
    }
}
void dfs(ll vertex){
    vis[vertex] = 1;
    for (auto u in adj[vertex]){
        if(vis[u] == 1){
            continue;
        }
        else {
            dfs(u);
        }
    }
}


int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ll n, m,q;
    ll a, b, w;
    cin>>n>>m;
    // cout<<"size fo n = "<<(sizeof(n))<<endl;
    for (int i =0; i< m; i++){
        cin>>a>>b;
        adj[a].pb(b);
        indegree[b]++;
    }

    topological_sort(n, top_sort, indegree);
    dfs(1);
    max_dist[1] = 0;
    if(vis[n] == 0){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        for (auto vertex in top_sort){
            if(vis[vertex] == 0){
                continue;
            }
            else{
                for (auto neighbour in adj[vertex]){
                    if(max_dist[neighbour] < max_dist[vertex] + 1){
                        parent[neighbour] = vertex;
                        max_dist[neighbour] = max_dist[vertex] + 1;
                    }
                }
            }
        }
        cout<<max_dist[n] + 1<<endl;    
        ll x = n;
        vector<ll>path;
        while(x != -1){
            path.push_back(x);
            x = parent[x];
        }
        reverse(path.begin(), path.end());
        for (auto vertex in path){
            cout<<vertex<<" ";
        }
        cout<<"\n";
    }
    
   
}