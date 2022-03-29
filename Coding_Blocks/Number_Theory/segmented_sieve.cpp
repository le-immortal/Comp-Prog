#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define test(t) while(t--)
#define fo(i,a,n) for(int i = a; i < n; i++)
#define pb push_back
#define popb pop_back
#define MOD 1000000007
#define newline <<'\n';

const int N = 100000;
vector <int> primes;
int p[N] = {0};

void sieve(){
	for(int i = 2; i <= N; i++){
		if(p[i] == 0){
			primes.push_back(i);
			for(int j = i; j <=N; j+=i){
				p[j] = 1;
			}
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	sieve();

	int t;
	cin >> t;
	test(t){
		int n, m;
		cin >> m >> n;

		bool segment[n-m+1];
		fo(i,0,(n-m+1)){
			segment[i] = 0;
		}
		// segmented sieve logic

		for(auto x: primes){

			if(x*x > n)
				break;

			int start = (m/x)*x;

			if(x>=m and x<=n){
				start = x*2;
			}
			for(int i = start; i <=n; i+=x){
				segment[i-m] = 1;
			}
		}

		for(int i = m; i <=n; i++){
			if(segment[i-m] == 0 and i!=1){
				cout << i << endl;
			}
		}cout << endl;
	}

	return 0;
} 