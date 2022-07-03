# Bellman Ford
on the i'th stage all my relaxations will occur at a distance >= i
```C++
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
}
```

### Dijkstra

Greedy, make sure you check if its visited both at hte start and at the ending because it is possible because of multiple edges that the same vertex is pushed out again from the queue

```C++
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
```
### Negative Cycles:-

---

N'th stage will involve multiple relaxations ( one of which will lie in a cycle edge for sure)
we can return to the cycle edge by taking a few steps back ( since all the relaxations that occur after n - 1 'th stage have propagated from the cycle itself, then we move backwards and find this starting position, and then we print the cycle)
```C++
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
```