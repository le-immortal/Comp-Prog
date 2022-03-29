#include <iostream>
using namespace std;

// Base class
class Shape
{
public:
	Shape(int l, int w)
	{
		length = l;
		width = w;
		cout << "Shape\n";
	} // default constructor
	Shape(){
		cout << "Khush";
	}
	void get_Area()
	{
		cout << "This is call to parent class area" << endl;
	}

	virtual void defi(){
		cout << "hello";
	}

	virtual void abstr() = 0;

protected:
	int length, width, area;
};

// Derived class
class Square :virtual public Shape
{
public:
	Square(int l = 0, int w = 0)
		: Shape(l, w)
	{
		cout << "Square\n";

	} // declaring and initializing derived class
	// constructor
	int get_Area()
	{
		cout << "Square area: " << length * width << endl;
		return (length * width);
	}
	// void abstr(){
	// 	cout << "Hello";
	// }
};
// Derived class
class Rectangle :virtual public Shape
{
public:
	Rectangle(int l = 0, int w = 0)
		: Shape(l, w)
	{		cout << "Rectangle\n";

	} // declaring and initializing derived class
	// constructor
	int get_Area()
	{
		cout << "Rectangle area: " << length + width
			<< endl;
		return (length * width);
	}
	void abstr(){
		cout << "new";
	}
};
class Something : public Square, public Rectangle{
public:
	Something(int l = 0, int w = 0):Square(l,w),Rectangle(l,w){
		cout << "Something\n";

	}
	int get_Area(){
		cout << "Something";
		return 0;
	}
};

int main(void)
{
	// Shape* s;
	// Square sq(5, 5); // making object of child class Square
	// Rectangle rec(
	// 	4, 5); // making object of child class Rectangle

	// s = &sq;
	// sq.get_Area();
	// s->get_Area();
	// s = &rec;
	// s->get_Area();
	Something *s = new Something(10,10);
	s->get_Area();
	return 0;
}
