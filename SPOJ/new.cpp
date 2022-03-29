#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define test(t) while(t--)
#define fo(i,a,n) for(int i = a; i < n; i++)
#define pb push_back
#define popb pop_back
#define MOD 1000000007
#define newline <<'\n';



int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int T;
	cin >> T;
	int h, w, n;
	vector <int> vx, vy;
	test(T){
		cin >> w >> h >> n;
		int x, y;
		fo(i,0,n){
			cin >> x >> y;
			vx.pb(x);
			vy.pb(y);
		}
		sort(vx.begin(), vx.end());
		sort(vy.begin(), vy.end());
		int maxx = vx[0]-1, maxy = vy[0]-1;

		fo(i,1,n){
			maxx = max(maxx, vx[i]-vx[i-1]-1);
			maxy = max(maxy, vy[i]-vy[i-1]-1);
		}
		maxx = max(maxx, w - vx[n-1]);
		maxy = max(maxy, h - vy[n-1]);		
		cout << maxx*maxy newline
		vx.clear();
		vy.clear();
	}

	return 0;
}