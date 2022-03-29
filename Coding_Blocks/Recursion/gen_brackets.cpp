#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define test(t) while(t--)
#define fo(i,a,n) for(int i = a; i < n; i++)
#define pb push_back
#define popb pop_back
#define MOD 1000000007

void generate_brackets(int N,int i, char *str, int open, int close){
	//base case
	if(i == 2*N){
		str[i] == '\0';
		cout << str << endl;
		return;
	}
	//rec case 
	if(open < N){
		str[i] = '(';
		generate_brackets(N, i+1,str, open+1, close);
	}
	if(close < open){
		str[i] = ')';
		generate_brackets(N, i+1, str, open, close+1);
	}
	return;
}



int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",  stdin);
	freopen("output.txt", "w", stdout);
#endif
	char str[100];

	generate_brackets(3,0,str, 0,0);
	return 0;


}	   