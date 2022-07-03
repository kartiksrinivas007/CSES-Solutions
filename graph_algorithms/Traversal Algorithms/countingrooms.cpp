/*
while all dots not marked 
    perrform dfs on unmarked dot 
    increment the count

*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>
#include <queue>
#include <deque>
#include <bitset>
#include <iterator>
#include <list>
#include <stack>
#include <map>
#include <set>
#include <functional>
#include <numeric>
#include <utility>
#include <limits>
#include <time.h>
#include <math.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <assert.h>
using namespace std;


int vis[1001][1001];
char grid[1001][1001];
int neighbourx[4] = {0 , 0 ,1 ,-1};
int neighboury[4] = {1 , -1 , 0 , 0};

bool isValid(int x, int y, int n, int m){
		if(x >0 && x < n && y > 0 && y < m)
			return true;
		else{
			return false;
		}
}

void dfs(int x, int y){
	vis[x][y] = 1; //this happesn at the beginnign fo dfs , i.e after dfs has been called not before the call of dfs
	for (int i = 0; i< 4; i++){
		int x_new = x + neighbourx[i];
		int y_new = y + neighboury[i];
		if(grid[x_new][y_new]== '.' && vis[x_new][y_new] == 0){
			dfs(x_new, y_new);
		}
	}
}


int main()
{
	#ifndef ONLINE_JUDGE
	freopen("input.txt","r",stdin);
	freopen("output.txt","w",stdout);
	#endif

  int n,m;
  cin>>n>>m;
  int i_A,j_A,i_B,j_B;
  for (int i=0;i<n;i++)
  {
	for (int j=0; j<m; j++){
		cin>>grid[i][j];
		if(grid[i][j]== 'A'){
			i_A = i;
			j_A = j;
		}
		if(grid[i][j]== 'B'){
			i_B = i;
			j_B = j;
		}
		
	}
  }
  
  dfs(i_A, j_A);
  if(vis[i_B][j_B] == 1){
	cout<<"YES"<<endl;
  }
  else{
	cout<<"NO"<<endl;
  }
// 	int num_of_components = 0;
//   for (int i=0; i<n ; i++){
// 	for (int j=0; j<m; j++){
// 		if(grid[i][j] == '.' && vis[i][j] == 0){
// 			num_of_components++;
// 			dfs(i,j);
// 		}
// 	}

//   }
// 	cout<<num_of_components<<endl;
  return 0;

	
}


