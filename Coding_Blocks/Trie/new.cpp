#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define test(t) while(t--)
#define fo(i,a,n) for(int i = a; i < n; i++)
#define pb push_back
#define popb pop_back
#define MOD 1000000007
#define newline <<'\n';

class Node{
public:
	Node *left;
	Node *right;
};

class Trie{
	Node *root;
public:
	Trie(){
		root = new Node();
	}

	void insert(int n){
		Node *temp = root;
		for(int i = 31; i >=0; i--){
			int bit = (n>>i) & 1;
			if(bit == 0){
				if(temp->left == NULL){
					temp->left = new Node();
				}
				temp = temp->left;
			}else{
				if(temp->right == NULL){
					temp->right = new Node();
				}
				temp = temp->right;
			}
		}
	}

	int max_xor_helper(int value){
				Node *temp = root;

		int current_ans = 0;
		for(int j = 31; j >= 0; j--){
			int bit = (value >> j) & 1;
			if(bit == 0){
				if(temp->right!= NULL){
					temp = temp->right;
					current_ans += (1 << j);
				}else{
					temp = temp->left;
				}
			}else{
				if(temp->left!= NULL){
					temp = temp->left;
					current_ans += (1 << j);
				}else{
					temp = temp->right;
				}
			}
		}
		return current_ans;
	}
	int max_xor(int *input, int n){
		int max_xor = 0;
		fo(i,0,n){
			int val = input[i];
			insert(val);
			int current_xor = max_xor_helper(val);
			max_xor = max(current_xor, max_xor);
			cout << current_xor << " ";
		}
		return max_xor;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	
	int input[] = {3,10,5,25,2,8};

	Trie t;
	cout << t.max_xor(input, 6); 
	return 0;
}