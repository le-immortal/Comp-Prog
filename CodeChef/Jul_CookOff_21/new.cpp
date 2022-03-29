#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define test(t) while(t--)
#define fo(i,a,n) for(int i = a; i < n; i++)
#define pb push_back
#define popb pop_back
#define MOD 1000000007
#define newline <<'\n';
#define mp make_pair 
#define F first 
#define c1(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" ";cout<<endl;
#define S second 

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T; 

	cin >> T;
	int x,y;
	test(T){
		int ans = 0;
		cin >> x >> y;
		if(x==1){
			ans++;
			x++;
		}
		if(y==1){
			ans++;
			y++;
		}
		if(!(x&1) && !(y&1)){
			cout << ans newline
			continue;
		}
		if(!(x&1) || !(y&1)){
			cout << ans+1 newline
			continue;
		}
		int h = x>y?x:y;
		int l = x>y?y:x;
		if(__gcd(x,y)>1){
			cout << ans newline
			continue;
		}
		if(__gcd(x+1,y)>1 || __gcd(x,y+1) == 0){
			cout << ans+1 newline
			continue;
		}
		cout << ans+2 newline
	}

	return 0;
}