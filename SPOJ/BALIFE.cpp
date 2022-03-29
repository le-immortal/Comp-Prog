#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define test(t) while(t--)
#define fo(i,a,n) for(int i = a; i < n; i++)
#define pb push_back
#define popb pop_back
#define MOD 1000000007
#define newline <<'\n';


// // Rebalancing proceeds in rounds. 
// In each round, every processor can transfer at most one job to each of its neighbors on the bus. 
// Neighbors of the processor i are the processors i-1 and i+1 (processors 1 and N have only one neighbor each, 2 and N-1 respectively). 
// The goal of rebalancing is to achieve that all processors have the same number of jobs.

// Given the number of jobs initially assigned to each processor, 
// you are asked to determine the minimal number of rounds needed to achieve the state when every processor has the same number of jobs
// , or to determine that such rebalancing is not possible. 

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r", stdin);
	freopen("output.txt", "w", stdout);
#endif

	int n;

	cin >> n;

	while(n!= -1){
		int load = 0;
		int arr[n];
		fo(i,0,n){
			cin >> arr[i];
			load+= arr[i];
		}
		if((load%n)){
			cout << -1 newline
			cin >> n;
			continue;
		}

		load = load/n;
		int max_load = 0;
		int diff = 0;
		fo(i, 0, n){
			 diff += arr[i] - load;
			 int ans = max(diff, -diff);
			 max_load = max(max_load, ans);
		}
		cout << max_load newline
		cin >> n;
	}

	return 0;
}