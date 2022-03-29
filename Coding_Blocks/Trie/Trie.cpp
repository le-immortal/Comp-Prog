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
	char data;
	int count;
	unordered_map <char, Node*>children;
	bool terminal;
	Node (char d){
		data = d;
		terminal = false;
		count = 1;
	}
};

class Trie{
	Node* root;
	int cnt;
public:
	Trie(){
		root = new Node('\0');
		cnt = 0;
	}

	void insert(char *w){
		Node *temp = root;
		for(int i = 0; w[i] != '\0'; i++){
			char ch = w[i];
			if(temp->children.count(ch)){
				temp = temp->children[ch];
				temp->count += 1;
			}else{
				Node* n = new Node(ch);
				temp->children[ch] = n;
				temp = n;
			}
		}
		temp->terminal = true;
	}

	bool find(char *w){
		Node* temp = root;
		for(int i = 0; w[i]!= '\0'; i++){
			char ch = w[i];
			if(temp->children.count(ch) == 0){
				return false;
			}else{
				temp = temp->children[ch];
			}
		}
		return temp->terminal;
	}

	string uniquePrefixArryay(char *w){
		Node* temp = root;
		string str;
		// cout << w;
		for(int i = 0; w[i]!= '\0'; i++){
			char ch = w[i];
			str += ch;
			// cout << temp->count << " " << i << " ";
			if(temp->children.count(ch)){
				temp = temp->children[ch];
				if(temp->count == 1){
					return str;
				}
			}
		}

		str = "";
		return str;
	}
};

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	
	Trie t;
	char words[][100] = {"cobra", "dog", "dog", "duck"};
	char w[10];

	for(int i = 0;i < 4; i++){
		t.insert(words[i]);
	}
	// cout << "hi";


	for(int i = 0; i < 4; i++){
		cout << t.uniquePrefixArryay(words[i]) newline
	}




	return 0;
}