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
// #ifndef ONLINE_JUDGE
// 	freopen("input.txt","r", stdin);
// 	freopen("output.txt", "w", stdout);
// #endif
	int T; 

	cin >> T;
	int N;
	test(T){
		cin >> N;
		int odd = 0;
		int x;
		fo(i,0,(2*N)){
			cin >> x;
			if(x&1){
				odd++;
			}
		}
		if(odd == N)
			cout << "Yes\n";
		else
			cout << "No\n";
	}

	return 0;
}