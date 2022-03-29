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
	vector <pair<string, int>> v;
	ll N, K;
	string S;

	test(T){
		cin >> N;
		
		for(ll i = 0; i < N; i++){
			cin >> S >> K;
			v.pb(make_pair(S,K));
		}
		vector <vector<string>> vec(N, {""});
		for(auto i : v){
			// cout << i.first << " " << i.second << endl;
			vec[i.second-1].pb(i.first);
		}	
   		// for (ll i = 0; i < N; i++){
    	// 	// cout << vec[i].size();
    	// 	if(vec[i].size()  > 1){
     //    	for (ll j = 0; j < vec[i].size(); j++)
     //    	{
     //        	cout << vec[i][j] << " ";
     //    	}   
     //    	cout << endl;
    	// 	}
   		// }
		ll rank = 1;
		ll badness = 0;
		for(ll i = 0; i < N; i++){
			if(vec[i].size() > 1){
				for(ll j = 1; j < vec[i].size(); j++){
					badness += abs(i+1 - rank);
					// cout << badness << " " << vec[i][j] << " ";
					rank++;
				}
			}
		}
		
		cout << badness << endl;

		v.clear();
	}

	return 0;
}