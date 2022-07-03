#include<bits/stdc++.h>
using namespace std;

typedef long long int ll ;
#define ii pair<long long int,long long int>
#define f first
#define s second
#define mp make_pair
#define pb push_back
#define MAXN 100002 //if this was larger that much space would nto be available !
#define in : 
#define MOD 1000000007
const ll INF = 1e17;

vector<vector<pair<ll,ll>>>adj(MAXN);
vector<ll>dist(MAXN, INF);
vector<ll>vis(MAXN, 0);
priority_queue<ii, vector<ii>, greater<ii>>pq;
vector<ll>max_vert_on_path(MAXN, -INF);
vector<ll>min_vert_on_path(MAXN, INF);
vector<ll>num_of_ssp(MAXN, 0);

void djk_modified(ll vertex){
    dist[vertex] = 0;
    min_vert_on_path[vertex] = 1;
    max_vert_on_path[vertex] = 1;
    num_of_ssp[vertex] = 1;
    pq.push(mp(0,vertex));

    while (!pq.empty()){
         ii popped = pq.top();
         pq.pop();
         if(vis[popped.s]){
            continue;
            //DO NOT PLAY HERE : - Don't push unnecessary stuff into the queue , rather just do it below when you are finding the members 
        //         //add count of target vertex
        //         if(popped.f == dist[popped.s]){
        //                 num_of_ssp[popped.s]++;
        //         }                
         }
         else{
                ll vertex_popped = popped.s;
                vis[vertex_popped] = 1;
                dist[vertex_popped] = popped.f;

                for (auto instance in adj[vertex_popped]){ 
                    if(dist[instance.f] < dist[vertex_popped] + instance.s)
                    {
                        continue;
                    }
                    else if(dist[instance.f]  ==  dist[vertex_popped] + instance.s){
                        num_of_ssp[instance.f] = (num_of_ssp[instance.f] + num_of_ssp[vertex_popped])%MOD
                        ; // crucial !! the quantity num_of_ssp will allready be fixed once i am searching vertex_popped's adjacency list! since i am now searching on a higher distance 
                        min_vert_on_path[instance.f] = min(min_vert_on_path[instance.f], min_vert_on_path[vertex_popped] + 1);
                        max_vert_on_path[instance.f] = max(max_vert_on_path[instance.f], max_vert_on_path[vertex_popped] + 1);

                    }
                    else{
                        dist[instance.f] = dist[vertex_popped] + instance.second;   
                        num_of_ssp[instance.f] = num_of_ssp[vertex_popped]; //found minimum?? at least proposed minimum up until now
                        min_vert_on_path[instance.f] = min_vert_on_path[vertex_popped] + 1;
                        max_vert_on_path[instance.f] = max_vert_on_path[vertex_popped] + 1;
                        pq.push({dist[vertex_popped] + instance.s, instance.first});
                    }
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
        adj[a].pb(mp(b,w));
    }

    djk_modified(1);
    cout<<dist[n]<< " "<<num_of_ssp[n]<<" "<<min_vert_on_path[n] - 1<<" "<<max_vert_on_path[n] - 1<<endl;

   return 0;

   
}