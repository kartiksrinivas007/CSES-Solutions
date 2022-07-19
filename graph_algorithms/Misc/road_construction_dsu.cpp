#include<bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define f first
#define s second
#define mp make_pair
#define pb push_back
typedef long long int ll;
#define MAXN 100002
vector<vector<pair<int, int>>> adj(MAXN);
vector<int>vis(MAXN,0);
vector<ll>parent(MAXN, -1);
vector<ll>size(MAXN, - 1);

//size is only and only stored at the parent!!

void make_set(ll v){
	parent[v] = v; //i am my own parent ( self loop)
	size[v] = 1;
}

//void find_set(ll v){
	//while(v != parent[v]){
		//v = parent[v]; //we need path compression here !!
	//}
	//return v;
//}
//in order to create a path compression we need to use a recursion stack ..and on the way above the recursion , we shall set the elements:-
ll find_set(ll v){
	if(v == parent[v]){
		return v;
	}
	ll par = find_set(parent[v]);
	parent[v] = par; //post recursion
	return par;
}


void union_set(ll v, ll w){
	if(find_set(v) == find_set(w)){
		return;
	}
	else{
		//join the two sets 
		//some sort of size optimization??
		ll a = find_set(v);
		ll b = find_set(w);
		if(size[a] > size[b]){
			parent[b] = a;
			size[a]  = size[a] + size[b];
		}
		else{
			parent[a] = b;
			size[b] = size[a] + size[b];
		}
	}
}




int main()
{
    #ifndef ONLINE_JUDGE
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    #endif
    int n, m;
    cin>>n;
    cin>>m;
    ll a,b;
    for (int i =1; i<= n; i++){
		make_set(i);
	}
	ll components = n;
	ll max_size = 1;
	for (int i =0; i< m; i++){
		cin>>a>>b;
		//any nice way to count the number of components ??
		if(find_set(a) == find_set(b)){
			cout<<components<<" "<<max_size<<endl;
		}
		else{
			components --;
			union_set(a, b);
			max_size = max(max_size, size[find_set(a)]);
			cout<<components<<" "<<max_size<<endl;
		}
		
	}
	//union_set(3, 4);
	//cout<<size[4]<<endl;
	//union_set(4, 5);
	//union_set(5, 6);
	//cout<<find_set(6)<<endl;
	//union_set(1, 2);
	//union_set(2, 3);
	//cout<<find_set(1)<<endl;
	//cout<<size[find_set(1)]<<endl;
	//cout<<parent[1]<<endl; //path compression is working !
	
    //cin>>n>>m;
    //for(int i=0; i< m; i++){
        //cin>>a>>b>>c;
        //adj[a].pb({b,c});
        //adj[b].pb({a,c});
    //}
 
    
return 0;
}
