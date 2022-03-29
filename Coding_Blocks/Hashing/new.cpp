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
	string k = "THISISSPIRALPRINT";
	int n = 4;
	int s = k.length();
	for(int i = 0; i < n; i++){
		int count = 0;
		for(int even = i, odd = 2*n-i-1; even < s || odd < s; ){
			if(count&1 and odd < s){
				cout << k[odd];
				odd+=2*n;
			}
			if(!(count&1) and even < s){
				cout << k[even];
				even += 2*n;
			}
			count++;
		}
		cout newlinen
	}
	return 0;
}