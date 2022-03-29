#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define test(t) while(t--)
#define fo(i,a,n) for(int i = a; i < n; i++)
#define pb push_back
#define popb pop_back
#define MOD 1000000007
#define newline <<'\n';

bool compare(pair<int, int>p1, pair<int,int> p2){
	return (p1.first/p1.second)>(p2.first/p2.second);
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T; 

	cin >> T;
	int N, M;
	vector<pair<int, int>>v ;
	test(T){
		v.clear();
		cin >> N >> M;
		test(N){
			int a,b;
			cin >> a >> b;
			v.pb(make_pair(a,b));
		}
		sort(v.begin(), v.end(), compare);
		// 	for(auto i : v){
		// 		cout << i.first << " " << i.second newline
		// }
		int ans=0, i =0;
		while(M >0){
			if(v[i].second<M){
				M -= v[i].second;
				ans+=v[i++].first;v.erase(v.begin());
				continue;
			}
			if(v[i].second/2 < M){
				M -= v[i].second/2;
				ans+= v[i++].first;
				continue;
			}
			break;
			// cout << M;
			
		}
		cout << ans newline
	}


	
	return 0;
}