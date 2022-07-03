#include<bits/stdc++.h>
using namespace std;


#define ii pair<long long int,long long int>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define MAXN 1001 //if thsi was larger that much space would nto be available !

typedef long long int ll;

vector<vector<ll>>distances(MAXN, vector<ll>(MAXN, LLONG_MAX));
vector<vector<pair<ll,ll>>>adj(MAXN);
vector<vector<ll>>vis(MAXN, vector<ll>(MAXN,0));
void djk(ll vertex);

void apsp(ll n){
    for (int i =1; i<=n; i++){
        djk(i);
    }
}

void djk(ll vertex){
    distances[vertex][vertex] = 0;
    priority_queue<ii,vector<ii>,greater<ii>>pq; // this can be used to define a min heap , the first entry being the distance
    // this has a remarkable similarity to the bfs ! (after all this is the same principle ( for shortest paths !, bag pull method))
    pq.push({0,vertex});
    while(!pq.empty()){
        ii popped = pq.top();
        pq.pop();
        ll dist_popped = popped.f;
        ll vertex_popped = popped.s;
        if(vis[vertex][vertex_popped]){
            continue;
        }
        else{
            vis[vertex][vertex_popped] = 1;

            for (auto x: adj[vertex_popped]){
                if(vis[vertex][x.f] == 0){
                    distances[vertex][x.f] = min(dist_popped + x.s, distances[vertex][x.f]);
                    pq.push({distances[vertex][x.f],x.f}); // this will take more time for updates 
                }
                else {
                    continue;
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

    ll n, m,q;
    ll a, b, w;
    cin>>n>>m>>q;
    // cout<<"size fo n = "<<(sizeof(n))<<endl;
    for (int i =0; i< m; i++){
        cin>>a>>b>>w;
        adj[a].pb(mp(b,w));
        adj[b].pb(mp(a,w));
    }
    // cout<<"size of adj = "<<(sizeof(adj))<<endl;
    // priority_queue<ii,vector<ii>,greater<ii>>pq;
    // pq.push({0,1});
    // pq.push({-1,35});
    // pq.push({-2,36});
    // cout<<pq.top().f<<"  "<<pq.top().s<<endl;
    apsp(n);
    for (int i =1; i<=q; i++){
        cin>>a>>b;
            if(distances[a][b] == LLONG_MAX){
                cout<<"-1\n";
            }
            else{
                cout<<distances[a][b]<<"\n";
            }
    }
   
}