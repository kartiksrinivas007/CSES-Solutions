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
vector<int>dist(MAXN,0);
vector<int>parent(MAXN,-1);
vector<ii>cycles;
vector<int>cycle;
void dfs_cycle(int vertex){
    vis[vertex] = 1;
    for(auto x: adj[vertex]){
        if(vis[x]){
            if(x == parent[vertex]){
                continue;
            }
            else {
                //cycle detected 
                cycles.push_back(mp(vertex,x));
            }
        }
        else {
            parent[x] = vertex;
            dfs_cycle(x);
        }
    }
}
void print_cycle_value(int sv, int ev){
    if(sv == ev){
        cycle.push_back(sv);
        return;
    }
    if(sv != -1){
    print_cycle_value(parent[sv],ev);
    cycle.push_back(sv);
    }
}
// void print_cycle(vector<ii>cycles){
//     ii x = cycles[0];
//     print_cycle_value(x.first,x.second);  
// }


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
    }
    for (int i=1; i<=n; i++){
        if(!vis[i]){
            dfs_cycle(i);
        }
        else{
            continue;
        }
    }
    cout<<"fine till here"<<endl;
    if(cycles.size() < 1){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        print_cycle_value(cycles[0].second,cycles[0].first);
        cout<<cycle.size() + 1<<endl;
        for(auto x: cycle){
            cout<<x<<" ";
        }
        cout<<cycles[0].second<<endl;
        cout<<endl;

    }
    return 0;
}