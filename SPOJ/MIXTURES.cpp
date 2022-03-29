#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define test(t) while(t--)
#define fo(i,a,n) for(int i = a; i < n; i++)
#define pb push_back
#define popb pop_back
#define MOD 1000000007
#define newline <<'\n';

int a[1000];
ll dp[1000][1000];

ll sum(int s, int e ){
	ll ans = 0;
	fo(i,s,e+1){
		ans+=a[i];
		ans %= 100;
	}
	return ans;
}

ll solve(int s, int e){
	//Base
	if( s>= e)
		return 0;
	if(dp[s][e] != -1)
		return dp[s][e];
	dp[s][e] = INT_MAX;

	for(int k = s; k <=e; k++){
		dp[s][e] = min(dp[s][e],solve(s,k)+solve(k+1,e)+sum(s,k)*sum(k+1,e));

	}
	return dp[s][e];
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T;
	int n =2;
	test((n)){
		cin >> T;
		for(int i = 0; i< T;i++)
			cin >> a[i];
		fo(i,0,T)
			fo(j,0,T)
				dp[i][j] = -1;
		fo(i,0,T)
		cout << solve(0,T-1) << endl;
	}


	return 0;
}