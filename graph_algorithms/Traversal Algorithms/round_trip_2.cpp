//cycle in directed graph
//the has a beautiful idea of simulating exactly how the recursion stack works
//we will just mantain the vertex on which we are in the dfs throughout , and if we encounter ourselves again throu our own dfs, then we have suceeded
//we keep on pushing stuff to the stack when we do our dfs , and we keep on popping it off the stack when we no longer care
#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
#define MAXN 100005
#define in :  
vector<vector<ll>>adj(MAXN);
vector<ll>vis(MAXN, 0);
vector<ll>is_tracked(MAXN, 0);
stack<ll>recursion_stack;
vector<ll>cycle;


bool dfs_cycle(ll vertex){ //returns true if a cycle is encountered when we would have done dfs(v) , i.e it looks ofr cycles specific to v's path of starting
    vis[vertex] = 1;
    is_tracked[vertex] = 1;
    recursion_stack.push(vertex); //push the current vertex because that is the content of the recursion stack 
        for (auto v in adj[vertex]){
            //really cool tech that will help you exit a dfs whenever a condition has become true
            if(!vis[v]){
                if(dfs_cycle(v)){
                    return true; //this behaves almost like a goto 
                }
            }

            if(is_tracked[v]){
                recursion_stack.push(v);
                return true; //start the exit conditon
            }

            //else there is no way this dude was part of a cycle else his dfs would have doen the job
        }
        //on completing all my neighbours , I am about to be pushed off from the stack, i dont need to be tracked anymore
        //checked and there were absolutely no cycles under me ! push me out ! untrack me !
        is_tracked[vertex] = 0;
        recursion_stack.pop();
        return false;
}
int main(){

    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    #ifndef ONLINE_JUDGE
    freopen("input.txt","r", stdin);
    freopen("output.txt","w", stdout);
    #endif

    ll n, m;
    cin>>n>>m;
    ll x, y;
    for(ll i =0; i< m; i++){
        cin>>x>>y;
        adj[x].push_back(y);
    }
    bool flag = false;
    for (ll i = 1; i <= n; i++){
        if(!vis[i]){
            if(dfs_cycle(i)){
                flag = true;
                ll first = recursion_stack.top();
                recursion_stack.pop();
                cycle.push_back(first);
                while(recursion_stack.top() != first){
                    ll vert = recursion_stack.top();
                    recursion_stack.pop();
                    cycle.push_back(vert);
                }
                cycle.push_back(recursion_stack.top());
                reverse(cycle.begin(), cycle.end());
                cout<<cycle.size()<<endl;
                for (auto vertex in cycle){
                    cout<<vertex<<" ";
                }
                cout<<"\n";   
                break;    
            }
            else{
                // std::fill(is_tracked.begin(), is_tracked.end(), 0); //takes too much time !!!!!!!!!111   
                // recursion_stack = stack<ll>();
                continue;
            }
        }
    }
    if(flag == false){
        cout<<"IMPOSSIBLE"<<endl;
    }
    return 0;
}