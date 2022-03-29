#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define test(t) while(t--)
#define fo(i,a,n) for(int i = a; i < n; i++)
#define pb push_back
#define popb pop_back
#define MOD 1000000007
#define newline <<'\n';

string solve(string s, string p){
	int ns = s.length();
	int ps = p.length();

	if (ps > ns)
	{	
		return "None";
	}
	int hashp[256] = {0};
	int hashs[256] = {0};

	for (int i = 0; i < ps; ++i)
	{
	 	hashp[p[i]]++;
	}
	int count = 0, start = 0;
	int start_idx = -1;
	int min_len = INT_MAX;
	for (int i = 0; i < ns; ++i)
	{
		char ch = s[i];
		hashs[ch]++;
		if(hashs[ch] <= hashp[ch]){
			count++;
		}

		if(count == ps){
			char temp = s[start];
			while(hashs[temp]>hashp[temp] || hashp[temp] == 0){
				if(hashs[temp] > hashp[temp])
					hashs[temp]--;
				temp = s[++start];
			}

			int len = i - start + 1;
			if(len < min_len){
				min_len = len;
				start_idx = start;
			}
		}
		cout << count << " ";

	}
	cout newline
	if (start_idx == -1)
	{
		return "none";
	}
	return s.substr(start_idx, min_len);

}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	string s = "hllloeaeo world heelo";
	string p = "heelo";

	
	
	cout << solve(s,p);
	return 0;
}