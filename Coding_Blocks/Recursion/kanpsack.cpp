#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define test(t) while(t--)
#define fo(i,a,n) for(int i = a; i < n; i++)
#define pb push_back
#define popb pop_back
#define MOD 1000000007


int profit(int N, int C, int *wt, int *prices){
	if(N == 0 || C == 0){
		return 0;
	}

	int ans = 0;
	int inc, exc;
	inc = exc = INT_MIN;
	if(wt[N-1] <= C){
		inc = prices[N-1] + profit(N-1, C-wt[N-1], wt, prices);
	}
	exc = profit(N-1, C, wt, prices);

	ans = max(inc, exc);
	return ans;
}

int main(){
#ifndef ONLINE_JUDGE
	freopen("input.txt","r",  stdin);
	freopen("output.txt", "w", stdout);
#endif
	int weights[] = {1,2,3,5};
	int prices[] = {40,20,30,100};

	int N = 4;
	int C = 7;
	cout << profit(N, C, weights, prices);
	return 0;


}	   