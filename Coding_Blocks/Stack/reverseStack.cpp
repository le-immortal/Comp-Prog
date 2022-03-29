#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define test(t) while(t--)
#define fo(i,a,n) for(int i = a; i < n; i++)
#define pb push_back
#define popb pop_back
#define MOD 1000000007
#define newline <<'\n';

void insertBottom(stack <int> &s,int x){
	if(s.empty()){
		s.push(x);
		return;
	}
	int temp = s.top();
	s.pop();
	insertBottom(s, x);
	s.push(temp);
}

void reverse1(stack <int> &s){
	if(s.empty()){
		return;
	}
	int n = s.top();
	s.pop();
	reverse1(s);
	insertBottom(s,n);
}

void reverse2(stack <int> &s1){
	stack <int> s2;

	int n = s1.size();

	for(int i = 0; i < n; i++){
		int x = s1.top();
		s1.pop();
		while(s1.size() != i){
 			s2.push(s1.top());
			s1.pop();
		}
		s1.push(x);	
		
		while(!s2.empty()){
			s1.push(s2.top());
			s2.pop();
		}
	}
}

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	stack <int> s;

	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);

	reverse2(s);

	while(!s.empty()){
		cout << s.top() newline;
		s.pop();
	}
	s.push(1);
	s.push(2);
	s.push(3);
	s.push(4);
	s.push(5);


	reverse1(s);

	cout newline
	while(!s.empty()){
		cout << s.top() newline;
		s.pop();
	}	
	return 0;
}