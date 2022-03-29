 #include<bits/stdc++.h>
using namespace std;
#define ll long long
#define test(t) while(t--)
#define fo(i,a,n) for(int i = a; i < n; i++)
#define pb push_back
#define popb pop_back

bool dfs_helper(vector<int>graph[], int node, int *visited,int parent, int color){
	visited[node] = color;
	for(auto nbr: graph[node]){
		if(visited[nbr] == 0){
			int sub = dfs_helper(graph,nbr, visited,node,3-color);
			if(sub == false)
				return false;
		}
		else if(nbr!=parent and color == visited[nbr]){
			return false;
		}
	}
	return true;
}

bool dfs(vector<int>graph[], int N){
	int visited[N] = {0}; //0 not visited // 1 and 2 for color
	int color = 1; 
	int ans = dfs_helper(graph,0,visited,-1, color);

	fo(i,0,N)
	cout << i << "-Color "<< visited[i] <<endl;
	return ans;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int N, M;
	cin >> N >> M;
	vector<int> graph[N];
	while(M--){
		int x,y;
		cin >> x >> y;

		graph[x].pb(y);
		graph[y].pb(x);

	}

	if(dfs(graph, N))
		cout << true;
	else
		cout << false;
	
	return 0;
}  