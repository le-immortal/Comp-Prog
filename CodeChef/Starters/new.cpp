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
	ll T, N, H;
	cin >> T;
	test(T){
		cin >> N >> H;
		vector<pair<ll, ll>> pos(N);
		fo(i,0,N)
			cin >> pos[i].first;
		fo(i,0,N){
			cin >> pos[i].second;
			pos[i].second -= H;
		}

		bool pass = true;
		ll moves = 0;
		for(auto x: pos){
			if(x.first <= x.second){
				pass = false;
				break;
			}
			moves = max(moves, (x.first+x.second+2)/2);
		}
		if(!pass)
			cout << "-1\n";
		else
			cout << moves newline
	}
	return 0;
			
}