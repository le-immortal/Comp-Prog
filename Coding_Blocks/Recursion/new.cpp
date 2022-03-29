#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define test(t) while(t--)
#define fo(i,a,n) for(int i = a; i < n; i++)
#define pb push_back
#define popb pop_back
#define MOD 1000000007

void generate_strings(char *in, char *out, int i, int j){
	if(in[i] == '\0'){
		out[j] = '\0';
		cout << out << endl;
		return;
	}
	int digit = in[i] - '0';
	if(digit > 0){
		out[j] = digit + 'a'-1;
		generate_strings(in, out, i+1, j+1);
	}

	if(in[i+1] != '\0'){
		
		digit = (in[i]-'0')*10 + (in[i+1]-'0');
		if(digit < 27){
			out[j] = digit + 'a' -1;
			generate_strings(in, out, i+2, j+1);
		}
	}
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",  stdin);
	freopen("output.txt", "w", stdout);
#endif


	char input[] = {'1', '2','3','4', '\0'};
	char output[100];

	generate_strings(input, output, 0, 0);
	return 0;
}	   