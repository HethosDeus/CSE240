#include <iostream>
using namespace std;

class MyClass {
public:   MyClass()
{
	cout << "MyClass constructed\n";
}
		  ~MyClass()
		  {
			  cout << "MyClass destroyed\n";
		  }
};

int main() {
	MyClass * pt;
	pt = new MyClass[3]; //since this is an array.  The delete will need to be an array, hence delete[]pt call
	// ...
	delete[] pt; //gets called three times.
	return 0;
}
/*
before the main() finish in the code before a delete instruction is needed.Which of the following options is correct ?
	a) delete pt;
	b) delete[] pt;
	c) for (int i = 0; i < 3; i++) { delete pt[i]; }
	*/
