#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define test(t) while(t--)
#define fo(i,a,n) for(int i = a; i < n; i++)
#define pb push_back
#define popb pop_back
#define MOD 1000000007
#define newline <<'\n';

bool solve(ll N, ll a,ll b){
	if(N == 1){
		return true;
	}
	if(!(N%a) && a != 1){
		ll n = N/a;
		return solve(n, a, b);
	}
	if(N-b >= 1){
		return solve(N-b, a, b);
	}
	return false;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt","r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	ll T; 

	cin >> T;
	ll N, A, B;
	test(T){
		cin >> N >> A >> B;
		if(solve(N, A, B)){
			cout << "Yes\n";
		}else
		 	cout << "No\n";
	}

	return 0;
}