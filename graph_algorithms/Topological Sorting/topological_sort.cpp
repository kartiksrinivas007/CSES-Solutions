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

vector<vector<ll>>adj(MAXN);
vector<ll>indegree(MAXN,0); //careful! 
vector<ll>top_sort;


void topological_sort(ll n, vector<ll> &top_sort, vector<ll>indeg){
    queue<ll>zero_in_deg;
    for (int i =1; i<=n; i++){
        if (indeg[i] == 0){
            zero_in_deg.push(i);
        }
    }
    // queue<ll>test(zero_in_deg);
    // cout<<zero_in_deg.size();
    // for (int i =0; i< test.size(); i++){
    //     cout<<test.front();
    //     test.pop();
    // }
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
    // for (int i =1; i<=n; i++){
    //     cout<<indegree[i]<<" ";
    // }
    // cout<<endl;

    topological_sort(n, top_sort, indegree);
    if(top_sort.size() < n){
        cout<<"IMPOSSIBLE"<<endl;
    }
    else{
        for (auto vertex in top_sort){
            cout<<vertex<<" ";
        }
        cout<<"\n";
    }
   
}