#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define test(t) while(t--)
#define fo(i,a,n) for(int i = a; i < n; i++)
#define pb push_back
#define popb pop_back
#define MOD 1000000007
#define newline <<'\n';

void counting_sort(int *a, int n){
	int largest = -1;
	fo(i,0,n){
		largest = max(largest, a[i]);
	}

	int *freq = new int[largest+1]{0};

	fo(i,0,n){
		freq[a[i]]++;
	}

	int j = 0;
	for(int i = 0; i<=largest; i++){
		while(freq[i] > 0){
			a[j] = i;
			freq[i]--;
			j++;
		}
	}
}

void dnf_sort(int a[], int n){

	int mid = 0;
	int l = n;

	for(int i =0; i< l;){
		if(a[i] == 0){
			swap(a[mid++], a[i++]);
		}
		if(a[i] == 2){
			swap(a[i], a[--l]);
		}else{
			i++;
		}
	}
	cout << mid << " " << l << " " newline

	return;

}
void waveform_sort(int a[], int n){
	for(int i = 0; i < n; i+= 2){
		if(i!=0 and a[i] < a[i-1])
			swap(a[i], a[i-1]);
		if(i!= (n-1) and a[i] < a[i+1])
			swap(a[i], a[i+1]);
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	int arr[] = {88, 97, 10, 12, 15, 1, 5, 6, 12, 51, 8};
	int n = sizeof(arr) / sizeof(int);

	counting_sort(arr, n);
	fo(i,0,n)
		cout <<arr[i] << " ";
	cout newline;

	int a[] ={2,1,1,1,1,0,1,0,2,2,1,0};
	n = sizeof(a)/ sizeof(int);

	dnf_sort(a, n);

	int wave[] = {1,3,4,2,7,8};

	fo(i,0,n)
		cout << a[i] << " ";
	cout newline;

	n = sizeof(wave)/sizeof(int);
	waveform_sort(wave, n);
	fo(i,0,n)
		cout << wave[i] << " ";

	return 0;
}