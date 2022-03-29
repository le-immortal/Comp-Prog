#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define test(t) while(t--)
#define fo(i,a,n) for(int i = a; i < n; i++)
#define pb push_back
#define popb pop_back
#define MOD 1000000007
#define newline <<'\n';
#define mp make_pair 
#define F first 
#define c1(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" ";cout<<endl;
#define S second 

class Graph
{
	map <int, list<int>> l;
	int vertices;
public:
	Graph(){
		
	}
	void insertEdge(int N, int M){
		l[N].pb(M);
		l[M].pb(N);
	}
	void print(){
		for(auto i : l){
			cout << i.first << ":";
			for(auto j : i.second)
				cout << j << "->";
			cout << endl;
		}
	}

	void minPath(int i, int N, int &minimum,  int pathlength, int &ans, int visited[]){
		if(i == N){
			if(pathlength == minimum){
				ans++;
			}
			if(pathlength < minimum){
				minimum = pathlength;
				ans = 1;
			}
			// cout << pathlength << " ";
			return;
		}
		if(visited[i])
			return;
		visited[i] = 1;
		for(auto j: l[i]){
			// cout << j << "->";
			if(visited[j] == 0){
				if(pathlength+1 > minimum){
					continue;
				}
				minPath(j,N,minimum,pathlength+1,ans,visited);
			}
			if(j == N)
				break;
			// cout << endl;
		}
		visited[i] = 0;
		return;
	}

	
};

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int N, M;
	cin >> N >> M;
	Graph g;
	int x,y;
	for(int i = 0; i < M; i++){
		cin >> x >> y;
		g.insertEdge(x,y);
	}
	int ans = 0;
	// g.print();
	int visited[N+1] = {0};
	int minimum = INT_MAX;
	g.minPath(1,N,minimum,0, ans, visited);
	// cout << endl;
	cout << ans;

	return 0;
}