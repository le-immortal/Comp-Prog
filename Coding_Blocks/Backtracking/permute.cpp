#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define test(t) while(t--)
#define fo(i,a,n) for(int i = a; i < n; i++)
#define pb push_back
#define popb pop_back
#define MOD 1000000007
#define newline <<'\n';

void permute(char*in, int i){
	//Base case
	if(in[i] == '\0'){
		cout << in newline
		return;
	}

	for(int j = i; in[j]!= '\0'; j++){
		swap(in[i], in[j]);
		permute(in, i+1);
		swap(in[i], in[j]);
	}
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	char in[100];
	cin >> in;

	permute(in, 0);
	return 0;
} 