// I have to get a shortest path after applying a discount on top of my system
// basically its a matter of choosing which parth on the way do i cut in half so that i can achieve s hortest path
//i fi i take all paths form 1 to 2 , then cutting one of them will decrease the path length( or weight ) , which such path do I choose
//one way is to find all paths from point 1 to point n (using a bfs/dfs)
//check sum(w) - max(pw)/2 = f(path) minimum amongst all paths 
//simply branch on the decision of cutting a cost in half fo revery edge in the graph
// dp[i][j][m] = shortest path form i to j by cutting the edge m ...thsi can be evaluated by DIjkstra in M logn time
// m^2 logn time for dijkstra these many times 
//meanign less way since this edge may not be part of any path from 1 to n 
//..say that i use my discount at point k , then i to k must be a sssp and then k to j will become also sssp 
//we can also use dp on f(path) instead of directly runnign on sum of wieghts  #dp now needs to carry information about the amximum weight edge seen up until that pooint
//lets just dolve fo rthe second term separately
//Q how will you print all paths from point 1 to point n ? how much time will this take ?
//let dp[i][j] be mas path length weight that comes from i and goes all the way to j , this can be made recursive (if topologically sorted)

//break down the process of going from a to b as a - > discount and then discount to b 
//to minimize thei sbasically brach on every edge, but don't run dijstra again and again
//baiscally stor the shortest paths form a  -> disocunt and disocunt ' to b , store them and then iterate over edges to find best solution
//to store the shortest path to b , we use an inverted graph !

#include<bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define f first
#define s second
#define mp make_pair
#define pb push_back

typedef long long int ll;

const ll INF  = 1e17;
const ll NINF = -1e17;
#define MAXN 100005
vector<vector<pair<ll,ll>>>adj(MAXN);
vector<ll>dist(MAXN, INF);
vector<ll>vis(MAXN,0);
vector<tuple<ll,ll,ll>>edges;
vector<ll>relaxant(MAXN, -1);

ll last_stage_relaxed;
void bellman_ford_modified(ll n , ll vertex){
    dist[vertex] = 0 ;
    for (int i =0; i<=n; i++){
        last_stage_relaxed = -1;
        for (auto edge : edges){
            ll u, v, w;
            tie(u, v, w) = edge;
            if(dist[u] == INF){
                continue;
            }
            else if (dist[u] + w < dist[v]){
                dist[v] = dist[u] + w;
                last_stage_relaxed = v;
                relaxant[v] = u;
            }
        }
    }

    if(last_stage_relaxed == -1){
        cout<<"NO"<<endl;
    }
    else {
        cout<<"YES"<<endl;

        // now time to return into the cycle by using the relaxants
        ll start_node = last_stage_relaxed;
        for (int i =0 ; i <= n; i++){
           start_node = relaxant[start_node];
        }

        vector<ll>cycle;
        for(ll v = start_node ;;v = relaxant[v]){
            if(v == start_node && cycle.size() >= 1){
                cycle.push_back(v);
                break;
            }
            else{
                cycle.push_back(v);
            }
        }
        reverse(cycle.begin(), cycle.end());

        for (auto vertex: cycle){
            cout<<vertex<<" ";
        }
        cout<<endl;
    }
}




int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    ll n, m;
    ll a, b,w;
    cin>>n>>m;
    
    for(int i=0; i< m; i++){
        cin>>a>>b>>w;
        adj[a].pb(mp(b,w));
        edges.push_back(make_tuple(a, b, w));
    }
    for (int i =1; i<=n; i++){
        edges.push_back(make_tuple(0,i,0));
    }

    bellman_ford_modified(n + 1, 0);

}