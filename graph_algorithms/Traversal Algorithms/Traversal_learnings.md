## Problem 1

---

```C++
bool isValid(int x, int y, int n, int m){
		if(x >0 && x < n && y > 0 && y < m)
			return true;
		else{
			return false;
		}
}
```

Sometimes its helpful to mantain an isValid function that looks like this and dfs through a  grid

## Bipartiteness check , check the team of the parent (the color)
```C++
void bfs_bipart(int vertex){
    queue<int>q;
    q.push(vertex);
    vis[vertex] = 1;
    team[vertex] = 1;
    while(!q.empty()){
        int p = q.front();
        q.pop();
        for(auto x: adj[p]){
            if(!vis[x]){
                q.push(x);
                vis[x]=1;
                team[x] = (team[p]==1)?2:1;
            }
            else{
                if(team[x] == team[p]){
                    cout<<"IMPOSSIBLE"<<endl;
                    return;
                }
                else {
                    continue;
                }
            }
        }
    }
}
```
###

# Undigraph Cycle Detection
Ue dfs check all neighbours, if neighbour is discovered and it is not parent then a cycle is made, use this member and the previous to trace back the cycle

```C++
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
```
# Cycle in digraph

---

Mantain a recursion stack which simulates the content of the dfs stack when calling, if you reach a member during dfs and this member is present in the recursion stack then and only then is a cycle present

```C++
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
```