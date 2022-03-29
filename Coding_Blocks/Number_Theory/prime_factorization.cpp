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
	 test(T){
	 	int N; 
	 	cin >> N;
	 	for(int i = 2; i <= sqrt(N); i++){
	 		if(N%i == 0){
	 			cout << i << " ";
	 			while(!(N%i)){
	 			N = N/i;
	 			}
	 		}
	 	}
	 	if(N != 1){ 
	 		cout << N << " ";
	 	}
	 	cout newline;
	 }
	return 0;
} 