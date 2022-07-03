// #include<bits/stdc++.h>
// using namespace std;


// #define ii pair<int,int>
// #define f first
// #define s second
// #define mp make_pair
// #define pb push_back

// #define MAXN 100001
// vector<vector<ii>> adj(MAXN);
// vector<int>vis(MAXN,0);
// vector<int>distances(MAXN,INT_MAX);
// vector<int>parent(MAXN,-1);
// struct compareintint{
//     bool operator()(const ii& a, const ii& b){
//         return a.s > b.s;
//     }
// };
// priority_queue<ii,vector<ii>,compareintint>pq;

// void djk(int vertex){
//     distances[vertex] = 0;
//     pq.push(mp(vertex,0));
//     while(!pq.empty()){
//         ii popped = pq.top();
//         pq.pop();
//         int u = popped.f;
//         int d = popped.s;
//         if(vis[u]){
//             continue;
//         }
//         else{
//             vis[u] = 1;
//             distances[u] = d;
//             for(auto x: adj[u]){
//                 if(!vis[x.f]){
//                     if(distances[x.f] > distances[u] + x.s){
//                         distances[x.f] = distances[u] + x.s;
//                         pq.push(mp(x.f,distances[x.f])); // push only if the previous distance is greater than the new distance
//                     }
//                     else{
//                         continue;
//                     }
//                 }
//             }
//         }
//     }
// }
// int main()
// {
//     #define int long long int

//     #ifndef ONLINE_JUDGE
//     freopen("input.txt","r",stdin);
//     freopen("output.txt","w",stdout);
//     #endif

//     int n, m;
//     int a, b, w;
//     cin>>n>>m;
//     // cout<<"size fo n = "<<(sizeof(n))<<endl;
//     for (int i =0; i< m; i++){
//         cin>>a>>b>>w;
//         adj[a].pb(mp(b,w));
//     }
//     djk(1);
//     for(int i=1; i<=n; i++){
//         cout<<distances[i]<<" ";
//     }

//     return 0 ;
//     // pq.push(mp(1,11));
//     // pq.push(mp(2,-6));
//     // pq.push(mp(-1,35));
//     // cout<<pq.top().f<<" "<<pq.top().s<<endl;
//     // pq.pop();
//     // cout<<pq.top().f<<" "<<pq.top().s<<endl;
// }
#include<bits/stdc++.h>
using namespace std;


#define ii pair<long long int,long long int>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define MAXN 100001

typedef long long int ll;

vector<vector<ll>>distances(2, vector<ll>(MAXN, LLONG_MAX));
vector<vector<pair<ll,ll>>>adj(MAXN);
vector<vector<ll>>vis(2, vector<ll>(MAXN,0));
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
    cin>>n>>m;
    // cout<<"size fo n = "<<(sizeof(n))<<endl;
    for (int i =0; i< m; i++){
        cin>>a>>b>>w;
        adj[a].pb(mp(b,w));
    }
    djk(1);
    for (int i =1; i<=n; i++){
        cout<<distances[1][i]<<" ";
    }
    cout<<endl;
   
}