/*• Write a C++ class (named Exam) with a static variable counter. counter increase in 1 each time that a new object is created.
Therefore, printing the value of counter, after running the following lines, should print the value 6.
Exam a1, a2, a3, a4, a5;
Exam *a6 = new Exam;
*/

#include <iostream>
using namespace std;
//If you want to count the number of objects of a specific class,
//you can use a static counter. Something like below..
//Increment counter on creation and decrement while destruction..
class Exam
{
public:
	static int counter;

	Exam()
	{
		//code..
		counter++;
	}

	virtual ~Exam()
	{
		//code..
		counter--;
	}
};

int Exam::counter = 0;

int main() {

	Exam a1, a2, a3, a4, a5; 
	Exam *a6 = new Exam;

	cout << Exam::counter << endl; //outputs 6
		
	return 0;
}


/*Write in C++ the following 3 classes. For each of them add a constructor and a destructor. 
Constructor and destructor print in the screen a message with the name of the class and the name of the method. 
For instance, “I am the constructor of the class Deer”. Create a class Animal. Create a class Vegetarian. 
Create a class Deer. Make the class Deer to inherits from Animal and from Vegetarian. Create a main() function.
Inside the main() function create a Deer object. Run your program. If everything is correct, the program should show 6 messages –
the call to the constructors and destructors for Deer, Animal, and Vegetarian.
*/

class Animal {
public:
	Animal() {

		cout << "I am the ctor for animal" << endl;
	}
	~Animal() {
		cout << "I am the dtor for animal" << endl;

	}

};

class Vegetarian {
public:
	Vegetarian() {
		cout << "I am the ctor for vegetarian" << endl;
	}
	~Vegetarian() {
		cout << "I am the dtor for vegetarian" << endl;
	}


};

class Deer: public Animal, Vegetarian {
public:
	Deer(): Animal(), Vegetarian() {
		cout << "I am the ctor for deer" << endl;
	}

	~Deer() {
		cout << "I am the dtor for deer" << endl;
	}

};

int main() {

	Deer bambi;  //output 6 messages, like it should.
//	Vegetarian carrot;
//	Animal dog;

	return 0;
 }
