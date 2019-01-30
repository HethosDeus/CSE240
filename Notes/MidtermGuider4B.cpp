/*• Use the language C++. Create a class Ball. Put 2 variables inside: an array of chars to store a color and an integer to store an id
• Ask the user for a number using cin
• Use the number that the user provides to create an array of objects Ball.
The number represent how many elements the array should have.
Store in the first position of the array an object with color= blue and id=1.
*/

#include <iostream>
using namespace std;

class Ball {
public:

	char *color;
	int id;
};

int main() {

	int user;

	cout << "Enter a number: ";
	cin >> user;

	class Ball *arrBalls = new Ball*[user];

	arrBalls[0].color = "blue";
	arrBalls[0].id = 1;
	cout << "Ball array size: \n" << user << endl;
	cout << "Ball color: \n" << arrBalls[0].color << endl;
	cout << "Ball id: %d \n" << arrBalls[0].id << endl;

	return 0;
};
