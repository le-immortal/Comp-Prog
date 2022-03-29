#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define test(t) while(t--)
#define fo(i,a,n) for(int i = a; i < n; i++)
#define pb push_back
#define popb pop_back
#define MOD 1000000007
#define newline <<'\n';

const int n = 10000000;
bitset <10000005> b;
vector <int> primes;

void sieve(){
	b.set();

	b[0] = b[1] = 0;

	for(ll i = 2; i <=n; i++){
		if(b[i]){
			primes.push_back(i);
			for( ll j = i*i; j <= n; j+= i){
				b[j] = 0;
			}
		}
	}
}

bool isPrime(ll No){
	if(No <= n){
		return b[No] == 1 ? true: false;
	}
	for(long long int i = 0; primes[i]*(ll)primes[i] <=No; i++){
		if(No % primes[i] == 0)
			return false;
	}
	return true;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	sieve();

	if(isPrime(2147483648)){
		cout << "Yes";
	}else
		cout << "No";

	return 0;
} 