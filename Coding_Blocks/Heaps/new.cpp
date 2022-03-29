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

class Heap
{
	vector<int> v;
	bool minHeap;
	bool compare(int a, int b){
		if(minHeap){
			return a < b;
		}else{
			return a > b;
		}
	}

	void heapify(int i){
		int left = 2*i;
		int right = left + 1;
		int min_idx = i;
		int last = v.size() -1 ;

		if(left <= last && compare(v[left], v[i])){
			min_idx = left;
		}
		if(right <= last && compare(v[right], v[min_idx])){
			min_idx = right;
		}

		if(min_idx != i){
			swap(v[i], v[min_idx]);
			heapify(min_idx); 
		}
	}
public:
	Heap(int default_size = 10, bool type = true){
		v.reserve(default_size);
		v.pb(-1);
		minHeap = type;
	}

	void push(int d){
		v.pb(d);
		int idx = v.size() -1;
		int parent = idx/2;
		while(idx > 1 and compare(v[idx],v[parent])){
			swap(v[idx], v[parent]);
			idx = parent;
			parent /= 2;
		}
	}
	int top(){
		return v[1];
	}

	void pop(){
		int last = v.size() - 1;
		swap(v[1], v[last]);
		v.popb();
		heapify(1);
	}
	bool empty(){
		return v.size() == 1;
	}

	void print(){
		for(auto i : v){
			cout << i << " ";
		}
	}
	// ~Heap();
	
};

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	// int T; 

	// cin >> T;

	// test(T){
	
	// }
	int arr[] = {1,2,5,10,9,8,3};
	int n = sizeof(arr)/sizeof(int);

	Heap h;
	fo(i,0,n)
		h.push(arr[i]);
	while(!h.empty()){
		cout << h.top() << " ";
		h.pop();
	}
	// h.print();
	return 0;
}