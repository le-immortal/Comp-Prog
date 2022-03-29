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
	int n, c1, c2, x;
	test(T){
		cin >> n;
		c1 = c2 = n/3;
		x = n%3;
		if(x == 0){
			cout << c1 << " " << c2 newline
		} else if(x == 1){
			cout << c1+1 << " " << c2 newline
		}else{
			cout << c1 << " " << c2+1 newline
		}
	}

	return 0;
}