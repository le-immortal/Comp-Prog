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
	string s;
	unordered_map <char, int> m;
	test(T){
		cin >> s;
		for(int i = 0;i < s.length(); i++){
			m[s[i]]++;
		}
		int count =0;
		int one = 0;
		for(auto i : m){
			if(i.second>=2){
				count++;
			}
			else if(i.second == 1){
				if(one){
					count++;
					one = 0;
				}else{
					one = 1;
				}
			}
		}
		cout << count newline
		m.clear();
	}

	return 0;
}