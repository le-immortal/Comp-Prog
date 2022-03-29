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

class Car
{
	float price;
public:
	int model_name;
	char *name;
	const int msp;
	Car():msp(99){
		cout << "Constructor\n";
		name = NULL;
	};
	Car(const Car &X):msp(X.msp){
		cout << "copy";
		price = X.price;
		model_name = X.model_name;
		name = new char[strlen(X.name)+1];
		strcpy(name,X.name);
	}
	void operator=(Car &X){
		cout << "copy assignment\n";
		price = X.price;
		model_name = X.model_name;
		name = new char[strlen(X.name)+1];
		strcpy(name,X.name);
	}
	Car(float p, int m, char *n):msp(90){
		price = p;
		model_name = m;
		name = new char[strlen(n)+1];
		strcpy(name, n);
	}

	void setprice(int p){
		price = p;
	}

	void print(){
		cout << "Name " << name << endl;
		cout << "Model " << model_name << endl;
		cout << "Price " << price << endl;
	}
	// friend ostream& operator << (ostream &out, const Car &c);
	
	~Car(){
		cout << "Destroy car " << name;
		if(name!=NULL)
			delete [] name;
	}
};

// ostream& operator << (ostream &out, const Car &c){
// 		out << "Name " << c.name;
// 		out << "\nmodel_name " << c.model_name;
// 		return out;
// 	}
std::ostream& operator<<(std::ostream& os, const Car &c){
		os << c.name << endl << c.model_name;
		return os;
	}
int main(){
	Car c(100,200,"BMW");
	Car d;
	Car e;
	cout << "hi\n";
	Car f(c);
	d = c;
	d.name[0] = 'A';
	d.setprice(400);
	c.print();
	d.print();
	cout << endl;
	cout << "SUccess\n";
	cout << c;

	return 0;
}