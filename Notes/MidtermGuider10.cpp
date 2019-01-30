/*		
10.  Arrays and Objects 
	 a) Create a class Student that has a constructor that prints “Hello, I am a student”.
	 b) In the class Student put a destructor that prints “Good bye, Student out”.
	 c) Create a class Course that has an array of 10 Students and initialize it
	 d) Create a class University that has an array of 10 Courses and initialize it 
	 e) Create, in a main() function, one and only one object University.
	 f) There is NOT inheritance here. Not at all. 
	g) Add constructors and destructors as needed in the classes Student and University . 
	h) The program should print 200 messages on the screen – the constructor and the destructor messages
	for each of the 10 students for each of the 10 courses. Remember that constructors and destructors are called automatically
*/
#include <iostream>
using namespace std;

class Student {
public:
	static int counter;
	Student() { 
		cout << "Hello, I am student." << endl;
		counter++;
	}

	~Student() {
		cout << "Good bye, student out." << endl; 
		counter--;
	}
};

class Course : Student {
public:
	Course::Student course[10];

	Course(): Student () { 
		cout << "Hello, I am course." << endl;
	}

	~Course() { cout << "Good bye, course out." << endl; }
};

int Student::counter = 0;

class University : Course {
public:
	University::Course uni[10];

	University(): Course() { cout << "Hello, I am Uni." << endl; }

	~University() { cout << "Good bye, Uni out." << endl; }
};

int main() {

	University *obj;
	cout << Student::counter << endl; //prints 121  :/

	return 0;

}
