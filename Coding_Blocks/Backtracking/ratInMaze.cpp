#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define test(t) while(t--)
#define fo(i,a,n) for(int i = a; i < n; i++)
#define pb push_back
#define popb pop_back
#define MOD 1000000007
#define newline <<'\n';

bool ratInMaze(char maze[10][10], int soln[][10],int i, int j, int m, int n){
	if(i == m && j == n){
		soln[m][n] = 1;
		for(int i = 0;i <=m; i++){
			for(int j =0; j<=n; j++){
				cout << soln[i][j] << " ";
			}cout newline;
		}
		cout << endl;
		return true;
	}

	if(i > m || j > n)
		return false;
	if(maze[i][j] == 'X')
		return false;

	soln[i][j] = 1;

	bool right = ratInMaze(maze,soln,i,j+1,m,n);
	bool down = ratInMaze(maze, soln, i+1,j, m,n);

	soln[i][j] = 0;

	if(right || down)
		return true;
	return false;
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	char maze[10][10] = {
						"0000",
						"00X0",
						"000X",
						"0X00"
	};

	int soln[10][10] = {0};

	int m =4,n =4;
	bool ans = ratInMaze(maze,soln,0,0,m-1,n-1);
	if(ans == false)
		cout << "path doesn't exist";

	return 0;
} 