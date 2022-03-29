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
	 int n, k;
	 test(T){
	 	cin >> n >> k;
	 	int ans = MOD;
	 	int occ;
	 	//factorization of K
	 	for(int i = 2; i < sqrt(k); i++){
	 		if(k%i == 0){
	 			occ = 0;
	 			while(!(k%i)){
	 				occ++;
	 				k /= i;
	 			}
	 			//Find out powers of i
	 			int cnt = 0;
	 			int p = i;
	 			while(p <= n){
	 				cnt+= n/p;
	 				p = p*i;
	 			}
	 			ans = min(ans, cnt/occ);

	 		}
	 	}
	 	//prime factor left
	 	if(k>1){
	 		int cnt = 0;
	 		int p = k;
	 		while(p<=n){
	 			cnt += n/p;
	 			p*=k;
	 		}
	 		ans = min(ans, cnt);
	 	}
	 	if(ans == INT_MAX){
	 		ans = 0;
	 	}
	 	cout << ans << endl;
	 }
	return 0;
} 