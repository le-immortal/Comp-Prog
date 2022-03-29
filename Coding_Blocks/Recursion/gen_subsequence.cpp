#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define test(t) while(t--)
#define fo(i,a,n) for(int i = a; i < n; i++)
#define pb push_back
#define popb pop_back
#define MOD 1000000007

void generate_subsequence(char *in, char *out, int i, int j){
	//base case
	if(in[i] == '\0'){
		out[j] = '\0';
		cout << out << endl;
		return;
	}

	//rec case
	//include the current char
	out[j] = in[i];
	generate_subsequence(in,out,i+1, j+1);

	//exclude the current char
	generate_subsequence(in, out, i+1, j);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	 char input[] = "abc";
	 char output[10];

	generate_subsequence(input, output, 0,0 );
	return 0;


}	   