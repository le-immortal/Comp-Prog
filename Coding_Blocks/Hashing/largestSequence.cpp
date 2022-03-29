#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define test(t) while(t--)
#define fo(i,a,n) for(int i = a; i < n; i++)
#define pb push_back
#define popb pop_back
#define MOD 1000000007
#define newline <<'\n';

int findLargestSeq(int arr[], int n){
	unordered_map <int, int>m;

	fo(i,0,n){
		int num = arr[i];
		if(m.count(num -1) == 0 and m.count(num+1) == 0){
			m[num] = 1;
		}else if(m.count(num-1) and m.count(num+1)){
			int len1 = m[num-1];
			int len2 = m[num+1];

			int streak = len1 + len2 + 1;
			m[num-len1] = streak;
			m[num+len2] = streak;
		}
		else if(m.count(num-1) and !m.count(num+1)){
			int len = m[num-1];
			m[num-len] = len+1;
			m[num] = len+1;
		}else{
			int len = m[num+1];
			int streak = len+1;
			m[num+len] = len+1;
			m[num] = len+1;
		}	
	}
	int largest = 0;
	for(auto p : m){
		largest = max(largest, p.second);
	}
	return largest;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int arr[] = {14,5, 1, 2, 6, 3, 7, 8, 9, 13, 15, 11, 12, 13, 17};
	int n = sizeof(arr) / sizeof(int);

	cout << findLargestSeq(arr, n) << endl;
	return 0;
}