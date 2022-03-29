#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define test(t) while(t--)
#define fo(i,a,n) for(int i = a; i < n; i++)
#define pb push_back
#define popb pop_back
#define MOD 1000000007

int stringToInt(char *a, int n){
	if(n == 0)
		return 0;
	int digit = a[n-1] -'0';
	int small_ans = stringToInt(a, n-1);

	return small_ans*10 + digit;
}
 
void replacePi(char a[], int i){
	//base case
	if(a[i] == '\0' or a[i+1] == '\0') 
		return;
	//look for pi
	if(a[i] == 'p' and a[i+1] == 'i'){
		//shifting and replacement
		int j = i+2;
		//find end of array
		while(a[j]!='\0'){
			j++;
		}
		//shift to the right
		while(j>=i+2){
			a[j+2] = a[j];
			j--;
		}
		//replacement + recursive call
		// cout << "hi";
		a[i] = '3';
		a[i+1] = '.';
		a[i+2] = '1';
		a[i+3] = '4';
		replacePi(a, i+4);
	} else{
		replacePi(a, i+1);
	} 
	return;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	char a[] = "1234";
	int len = strlen(a);
	
	cout << stringToInt(a,len) << endl;

	char ae[] = "12pi1ddqpiedapi";
	len = strlen(ae);
	replacePi(ae, 0);
	cout << ae << endl;
	return 0;


}	