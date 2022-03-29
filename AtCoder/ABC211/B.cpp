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
	unordered_set<string>v;
	string s;
	for(int i = 0; i < 4; i++){
		cin >> s;
		v.insert(s);
		// cout << s newline
	}
	int count = 0;

	for(auto i : v){
		if(i == "3B" || i == "H" || i == "2B" || i == "HR"  )
			count++;
		// cout << v[i]<< " ";

	}
	if(count == 4)
		cout << "Yes";
	else
		cout << "No";
	return 0;
}