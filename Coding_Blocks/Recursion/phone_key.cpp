#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define test(t) while(t--)
#define fo(i,a,n) for(int i = a; i < n; i++)
#define pb push_back
#define popb pop_back
#define MOD 1000000007

char keypad[][10] = {"","", "ABC","DEF","GHI","JKL","MNO","PQRS","TUV","WXYZ"};

void gen_names(char *in, char*out, int i, int j){
	if(in[i] == '\0'){
		out[j] = '\0';
		cout << out << endl;
		return;
	}
	int digit = in[i] - '0';

	if(digit == 1 || digit == 0){
		gen_names(in, out, i+1, j);
	}
	for(int k = 0; keypad[digit][k] != '\0'; k++){
		out[j] = keypad[digit][k];
		//fill remaining part
		gen_names(in, out, i+1, j+1);

	}
	return;
	

}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",  stdin);
	freopen("output.txt", "w", stdout);
#endif

	char in[] = {'1','3','1','\0' };

	char out[100];
	gen_names(in, out, 0, 0);


	return 0;
}	   