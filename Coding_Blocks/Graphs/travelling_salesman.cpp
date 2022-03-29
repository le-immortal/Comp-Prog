 #include<bits/stdc++.h>
using namespace std;
#define ll long long
#define test(t) while(t--)
#define fo(i,a,n) for(int i = a; i < n; i++)
#define pb push_back
#define popb pop_back

int n = 4;
int dist[10][10] = {
	{0,20,42,25},
	{20,0,30,34},
	{42,30,0,10},
	{25,34,10,0}
};
	int dp[100][100];

//if all cities visited

int visited_all = (1 << n) -1;

int tsp(int mask, int pos){
	if(mask ==visited_all)
		return dist[pos][0];

	if(dp[mask][pos] != -1)
		return dp[mask][pos];
	int ans = INT_MAX;
	//try to go to unvisited cities
	fo(city,0,n){
		if((mask & (1 << city)) == 0){

			int newAns = dist[pos][city] + tsp(mask|(1 <<city), city);
			ans = min(ans, newAns);
		}
	}
	
	return dp[mask][pos] = ans;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	fo(i, 0, (1<<n))
		fo(j, 0, n)
			dp[i][j] = -1;
	
		
	cout <<  tsp(1,0) << endl;
	fo(i, 0, (1<<n)){

		fo(j, 0, n){
			cout << dp[i][j] << " "; 
		}
		cout <<endl;
		}
	return 0;
}  