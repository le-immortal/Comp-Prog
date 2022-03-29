#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define test(t) while(t--)
#define fo(i,a,n) for(int i = a; i < n; i++)
#define pb push_back
#define popb pop_back
#define MOD 1000000007
#define newline <<'\n';
ll a[1000005], pre[1000005];


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int T;
	 cin >> T;
	 test(T){
	 	int n;
	 	 cin >> n;
	 	 memset(pre, 0, sizeof(pre));
	 	 pre[0] = 1;
	 	 int sum = 0;
	 	 fo(i,0,n){

	 	 	cin >> a[i];
	 	 	sum += a[i];
	 	 	sum%=n;

	 	 	sum = (sum+n)%n;
	 	 	pre[sum]++;
	 	 }
	 	 ll ans = 0;
	 	 fo(i,0,n){
	 	 	ll m = pre[i];
	 	 	ans+= m*(m-1)/2;
	 	 }
	 	 cout << ans << endl;

	  }
	return 0;
} 