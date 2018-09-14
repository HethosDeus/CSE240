/*Create a function that print the following. It should be recursive, i.e., 
DO NOT use for, do/while or while statements here. Output:
 1, 2, 3, 4, 5, 6, 7, 8, 9, 0, 9, 8, 7, 6, 5, 4, 3, 2, 1
 
 @Author:  Adam Clifton
*/
#include <iostream>

using namespace std;

void recursion_up(int num) {  //use recursive call to increment num < 10

	if (num == 10)
		cout << "0, ";

	if (num < 10) {
		cout << num << ", ";
		recursion_up(num + 1);
		
	} 
}

void recursion_down(int num) {//use recursive call to decrement num >= 1

	if (num >= 1) {
		cout << num << ", ";
		recursion_down(num - 1);
		
	}
}

// this is the simple way to do both: one function using symmetry with the cout << calls before and after the recursive step	
void recursion(int num) { 
	if (num == 10)
		cout << "0, ";
	
	if (num < 10) {
		cout << num << ", ";
		recursion(num + 1);
		cout << num << ", ";
	}
}


int main() {
	
	cout << "\nrecursion up: " << endl;
	recursion_up(1);
	cout << "\nrecursion down: " << endl;
	recursion_down(9);
	cout << "\nrecursion using a single method: " << endl;
	recursion(1);
	return 0;
}
