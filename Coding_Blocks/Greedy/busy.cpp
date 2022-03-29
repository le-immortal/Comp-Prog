#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define test(t) while(t--)
#define fo(i,a,n) for(int i = a; i < n; i++)
#define pb push_back
#define popb pop_back
#define MOD 1000000007
#define newline <<'\n';

bool compare(pair<int, int> p1, pair <int,int>p2){

return p1.second < p2.second;
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

	vector <pair<int,int>> v;
	int N;
	test(T){
		cin >> N;
		int start, end;
		fo(i,0,N){
			cin >> start >> end;
			v.pb(make_pair(start, end));
		}
		sort(v.begin(), v.end(), compare);
		int ans = 1;
		int fin = v[0].second;

		for(int i = 1; i < N; i++){
			if(v[i].first >= fin){
				fin = v[i].second;
				ans++;
			}
		}

		
		cout << ans newline
		v.clear();
	}

	return 0;
}