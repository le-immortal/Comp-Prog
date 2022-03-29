#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define test(t) while(t--)
#define fo(i,a,n) for(int i = a; i < n; i++)
#define pb push_back
#define popb pop_back
#define MOD 1000000007
#define newline <<'\n';

void stockSpan(int price [], int n, int span[]){
	stack <int> s;
	s.push(0);
	span[0] = 1;
	fo(i,0,n){
		int currentPrice = price[i];

		while(!s.empty() and price[s.top()] <= currentPrice){
			s.pop();
		}
		if(s.empty()){
			span[i] = i+1;
 		}else{

			int prevHigh = s.top();
			span[i] = i -prevHigh;
 		}
 		s.push(i); 
	}
}


int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int prices[] = {100,80,60,70,60,75,85};

	int n = sizeof(prices)/sizeof(int);
	int span[100000] = {0};

	stockSpan(prices, n, span);
	fo(i,0,n)
		cout << span[i] << " ";
	return 0;
} 