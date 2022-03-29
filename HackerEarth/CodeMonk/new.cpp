#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define test(t) while(t--)
#define fo(i,a,n) for(int i = a; i < n; i++)
#define pb push_back
#define popb pop_back
#define MOD 1000000007
#define newline <<'\n';
#define mp make_pair 
#define F first 
#define c1(a,n) for(int i=0;i<n;i++) cout<<a[i]<<" ";cout<<endl;
#define S second 

int mergeSort(int arr[][20],int row, int l, int mid, int r){
	int i = r;
	int j = mid+1;
	int k = r; int temp[100];
	int inv = 0;
	while(i<=mid && j<=r){
		if(arr[row][i] < arr[row][j]){
			temp[k++] = arr[row][i++];
		}else{
			temp[k++] = arr[row][j++];
			inv += mid-i;
		}
	}
	while(r<=mid)
		temp[k++] = arr[row][i++];
	while(j<=l)
		temp[k++] = arr[row][j++];
	fo(a,i,r+1)
		arr[row][a] = temp[a];
	return inv;
}

int merge(int arr[][20],int row,int l, int r){
	int inv = 0;
	if(l>=r)
		return 0;
	int mid = (r+l)/2;
	inv += merge(arr,row,l,mid);
	inv += merge(arr,row,mid+1,r);
	inv += mergeSort(arr,row,l,mid,r);
	return inv;
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	int T; 

	cin >> T;
	int n;
	test(T){
		cin >> n;
		int arr[10][20];
		fo(i,0,n)
			fo(j,0,n)
				cin >> arr[i][j]; 
		int inv = 0;
		fo(i,0,n){
			inv += merge(arr,i,0,n-1);
		}
		cout << inv newline
	}

	return 0;
}