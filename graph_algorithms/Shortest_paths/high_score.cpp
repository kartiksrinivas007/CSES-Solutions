#include<bits/stdc++.h>
using namespace std;


#define ii pair<long long int,long long int>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define MAXN 2500 //if this was larger that much space would nto be available !
#define in : 

typedef long long int ll;

const ll INF = 1e17;
const ll NINF = -1e17;

vector<vector<pair<ll,ll>>>adj(MAXN);
vector<ll>dist(MAXN, INF);
vector<tuple<ll,ll,ll>>edges;

void relax_bellman_ford(ll vertex, ll n){
    dist[vertex] = 0;
    for (int i =0 ; i< n; i++){
        for (auto edge in edges){
                ll u, v,w;
                tie(u, v, w) = edge;
                //check if i can relax this edge
                if(dist[u] == INF){
                    continue;
                }
                if(dist[u] + w < dist[v]){
                    // then we can relax
                    dist[v] = dist[u] + w;
                }
        }
    }

    //now i need to check for further relaxations , these relaxations will occur within a negative cycle and propagate forward
    //n - 1 more iterations for the update of our goal vertex [n] at worst case, because 2n-2 iterations are enought to find the path that takes the cycle and retursn to node n
    //stage i will ATLEAST CHECK ALL PATHS UPTO A LENGTH i There maybe greater length relaxations
    for (int i = 0; i<n; i++){
        for (auto edge in edges){
            ll u, v, w;
            tie(u,v,w) = edge;
            if(dist[u] == INF){
                continue;
            }
            //are all the vertices that can become NINF the same as the ones that are reachable form the first such vertex that becomes NINF
            if(dist[u] == NINF){
                dist[v] = NINF;
            }
            dist[v] = max(dist[v], NINF); // worst case on any vertex is NINF, I would not want to go below that
            if(dist[u] + w < dist[v]){
                // is u->v necessarily a part of the negative cycle????( I think no ) but for every stage ther will be atleast one update that lies in the negative cycle
                dist[v] = NINF;
            }
        }
    }

}



int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif

    ll n, m,q;
    ll a, b, w;
    cin>>n>>m;

    for (int i =0; i< m; i++){
        cin>>a>>b>>w;
        edges.push_back(make_tuple(a,b,-1*w));
    }
    relax_bellman_ford(1,n);
    if(dist[n] == NINF){
        cout<<-1<<'\n';
    }
    else{
        cout<<-1*dist[n]<<'\n';
    }

   return 0;

   
}