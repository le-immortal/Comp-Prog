#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define test(t) while(t--)
#define fo(i,a,n) for(int i = a; i < n; i++)
#define pb push_back
#define popb pop_back
#define MOD 1000000007
#define newline <<'\n';
template <typename T>
class Node{

public: 
	string key;
	T value;
	Node <T>*next;

	Node(string key, T val){
		this->key = key;
		value = val;
		next = NULL;
	}
	~Node(){
		if(next!=NULL){
			delete next;
		}
	}
};

template <typename T>
class Hashtable
{
	Node<T>** table;
	int current_size;
	int table_size;

	int hashFn(string key){
		int idx = 0;
		int p = 1;
		for(int j = 0; j < key.length(); j++){
			idx = idx + (key[j]*p)%table_size;
			idx = idx%table_size;
			p = (p*27)%table_size;
		}
		return idx;
	}

	void rehash(){
		Node<T>**oldTable = table;
		int oldTableSize = table_size;
		table_size = 2*table_size;
		table = new Node <T>*[table_size];

		for(int i =0 ;i < table_size; i++){
			table[i] = NULL;
		}

		current_size = 0;

		//shift the elements
		for(int i =0; i < oldTableSize; i++){
			Node<T>*temp = oldTable[i];
			while(temp!=NULL){
				insert(temp->key, temp->value);
				temp = temp->next;
			}
			if(oldTable[i]!=NULL){
				delete oldTable[i];
			}
		}
		delete [] oldTable;
	}



public:

	Hashtable(int ts=7){
		table_size = ts;
		table = new Node<T>*[table_size];
		current_size = 0;
		for(int i = 0; i < table_size; i++){
			table[i] = NULL;
		}
	}

	void insert(string key, T value){
		int idx = hashFn(key);
		Node <T>*n = new Node<T>(key, value);
		//add head of the linked list
		n->next = table[idx];
		table[idx] = n;
		current_size++;
		// print();
		float load_factor = current_size/(1.0*table_size);

		if(load_factor > 0.7){
			rehash();
		}
	
}
	void print(){
		for(int i = 0; i < table_size; i++){
			cout << "Bucket "<<i << "->" ;
			Node<T>*temp = table[i];
			while(temp!=NULL){
				cout << temp->value << "->";
				temp = temp->next;
			}
			cout << endl;
		}
	}

	T* search(string key){
		int idx = hashFn(key);
		Node <T> *temp = table[idx];
		while(temp!=NULL){
			if(temp->key == key){
				return &temp->value;
			}
			temp = temp->next;
		}
		return NULL;
	}	
	// T search(string key){

	// }

	// void erase(string value){

	// }

	
};

int main(){
	ios_base::sync_with_stdio(false);
    cin.tie(NULL);
#ifndef ONLINE_JUDGE
	freopen("input.txt","r", stdin);
	freopen("output.txt", "w", stdout);
#endif
	Hashtable<int> price_menu;
 
	price_menu.insert("Burger", 120);
	price_menu.insert("Pepsi", 50);
	price_menu.insert("Pizza", 40);
	price_menu.insert("Coke", 120);
	price_menu.insert("Coffee", 100);

	price_menu.print();

	int *price = price_menu.search("Coffee");
	if(price == NULL)
		cout << "Not found" << endl;
	else
		cout << *price << endl;
	return 0;
}