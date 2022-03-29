#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define test(t) while(t--)
#define fo(i,a,n) for(int i = a; i < n; i++)
#define pb push_back
#define popb pop_back
#define MOD 1000000007

void move(int n, char src, char helper, char dest){
	//base case
	if(n == 0)
		return;
	//rec case
	//move n-1 disk from src to helper
	move(n-1, src, dest, helper);
	cout << " Shift disk " << n << " from " << src << " to " << dest <<endl;

	move(n-1, helper, src, dest);
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int n;
	cin >> n;

	move(n,'A', 'B', 'C');

	return 0;


}	   