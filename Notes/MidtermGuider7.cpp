#include <iostream>
using namespace std;
/* Add the necessary code to make polymorphism work here. And, make this line  father->sayHello();  print “I am a Cube” when executed.
*/
class Line {
private:
	int length;
public:    
	
	virtual void sayHello() { cout << "I am Line"; }
	
}; 
	
class Square : public Line {
private:
	int high;
public:
	 void sayHello() { cout << "I am a square"; }
}; 
	
class Cube : public Square {
	
private: 
	int deep;
public:
		void sayHello() { cout << "I am a Cube";}
		
		// add functions here

		}; 
					 
		
int main() {
	Line *father;
	Cube cubi;
	father = &cubi;
	father->sayHello(); 	// prints “I am a Cube”
	return 0;
}  

// this is the example from the lectures 
class Figure {
protected:
	int width, height;
public:
	void set_values(int a, int b) 
	{
		width = a;
		height = b;
	}
	virtual int area() //polymorphism occurs here on this line for rect and tri classes
	{ 
		return 0;
	}
};

class Rectangle : public Figure {
public:
	int area()
	{
		return width * height;
	}
};

class Triangle : public Figure {
public:
	int area()
	{
		return width * height / 2;
	}
};

int main() {
	Rectangle rect;
	Triangle tri;

	Figure *f1 = &rect;
	Figure *f2 = &tri;

	f1->set_values(10, 20);
	f2->set_values(30, 40);

	cout << rect.area() << "\n";
	cout << tri.area() << "\n";

	cout << f1->area() << "\n";
	cout << f2->area() << "\n";


	return 0;

}
