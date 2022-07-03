#include<bits/stdc++.h>
using namespace std;

#define ii pair<long long int,long long int>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define MAXN 100001 //if thsi was larger that much space would nto be available !
#define in :
#define MOD 1000000007
#define rep(i,start, end) for(int i = start; i<end; i++)

typedef long long int ll;

const ll INF = 1e17;
const ll NINF = -INF;

vector<vector<ll>>adj(MAXN);
vector<vector<ll>>adj_reversed(MAXN);
vector<ll>top_sort;
vector<ll>indegree(MAXN, 0);
vector<ll>vis(MAXN,0);

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

int main(){

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ll n, m;
    cin>>n>>m;
    for (int i =0; i<m; i++){ // my god i wrote n here and not m !!
        ll a ;
        ll b;
        cin>>a>>b;
        adj[a].pb(b);
        indegree[b]++;
    }
    //Topological Sort
    //similar to prevois problem where the max lenght path was required
    //instead of that here the number of paths is needed 
    //to do that lets mantain dp[u]  = number of paths from number 1 to u.
    //dp[u+1] = 1 => nighbour(u+1) many that go to this neighbour and then neighbour(u+1) => u+1
    dfs(1);
    if (vis[n] == 0){
        // cout<<"NOt Visited "<<endl;
        cout<<0<<endl;
    }
    else {
        vector<ll>num_of_paths(MAXN, 0);
        topological_sort(n, top_sort, indegree);
        // //
        // for (auto v in top_sort){
        //     cout<<v<<" ";
        // }
        // cout<<endl;
        for(auto vertex in top_sort){
           if(vis[vertex] == 0){
                num_of_paths[vertex] = 0;
                continue;
           }
           
           else {
                if(vertex == 1){
                    // cout<<"setting to 1 \n";
                    num_of_paths[vertex] = 1;
                }
                for (auto neighbour in adj[vertex]){
                    num_of_paths[neighbour]  = (num_of_paths[neighbour]  +  num_of_paths[vertex])%MOD;
                    // cout<<"adding paths of "<<neighbour<<" using that of "<<vertex<<"\n";
                }
           }
        }
        // rep(i,1,n+1){
        //     cout<<vis[i]<<endl;
        // }
        // cout<<"\n";
        cout<<num_of_paths[n]<<endl;
    }


    return 0;
}