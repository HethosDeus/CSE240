/**

* Create method to initialize array by putting 0s in the odd index and 1s in the even indexes of an array.  Then create a method to print the array,
a method to use selection sort on the array in descending order, and a recursive method to find the factorial of an array index.

* Assignment 2 for CSE240

* @author Adam Clifton

* @version 2018.08.30

*/
#include <stdio.h>

/*Create a function initialize_array that receives two parameters: an array of integers and the array size.
Use a for loop and an if statement to put 1s in the odd positions of the array and 0s in the even positions.
Hint: review pointers as parameters.
*/
int initialize_array(int array[], int size) {

	int even = 0; int odd = 1;

	for (int *i = &array; *i; i++) {

		if (even < size) {
			array[even] = 0;
			even += 2;
		}
		if (odd < size) {
			array[odd] = 1;
			odd += 2;
		}
	}
}

/*Create a function print_array that receives as parameters an array of integers and the array size.
Use a for statements to print all the elements in the array.
Hint: review pointers as parameters.
*/
void print_array(int array[], int size) {

	for (int i = 0; i < size; i++) {

		printf("%d ", array[i]);
	}
	printf("\n");
}

/*Create a function selection_sort that receives as parameters an array of integers and the array size,
and order the array element in **descending order**
*/
int selection_sort(int array[], int size) {

	int maxIndex;

	for (int i = 0; i < size; i++) {
		maxIndex = i;

		for (int j = i + 1; j < size; j++) {

			if (array[j] > array[maxIndex]) {
				maxIndex = j;
			}
		}
		int temp = array[i];
		array[i] = array[maxIndex];
		array[maxIndex] = temp;
	}
}

/*Create a recursive function that calculate and returns the factorial of a number.
The function receives the number (integer number) as parameter
*/
int factorial(int number) {

	if (number == 0)					//base case
		return 1;					//base value
	else
		return number * factorial(number - 1);		//recursive subproblem
}

int main() {

	int a[10] = { 3,5,6,8,12,13,16,17,18,20 };
	int b[6] = { 18, 16, 19, 3 ,14, 6 };
	int c[5] = { 5, 2, 4, 3, 1 };

	// testing initialize_array
	print_array(a, 10); // print: 3, 5, 6, 8, 12, 13, 16, 17, 18, 20
	initialize_array(a, 10);
	print_array(a, 10); // print: 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 

	// testing selection sort
	print_array(b, 6); // print: 18, 16, 19, 3 ,14, 6
	selection_sort(b, 6);
	print_array(b, 6); // print: 19, 18, 16, 14, 6, 3

	// testing factorial
	printf("Factorial of 5 = %d\n", factorial(5)); //print: 120
	c[0] = factorial(c[0]);
	c[1] = factorial(c[2]);
	print_array(c, 5); // print: 120, 24, 4, 3, 1 

	//int x = 5;
	//int *y = &x;
	//printf("%d ", *y);
	// for (int i = 0; i < 5; i++)
	//	printf("%d ", array[i]);
}
