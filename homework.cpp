/**
* Description: This is the implementation file for Homework week 4, part 1.  This
file is linked to main_part1.cpp and homework.h
* Assignment 3 for CSE240
*
* @author Adam Clifton
* @version 2018.09.07
*/

#include <iostream>
#include "homework.h"
using namespace std;

/*Create a function initialize_array that receives two parameters: an array of integers and the array size.
Use a for loop and an if statement to put 1s in the odd positions of the array and 0s in the even positions.
Hint: review pointers as parameters.
*/
void Homework::initialize_array(int array[], int size) {

	int even = 0; int odd = 1;
	
	for (int i = 0; i < size; i++) {

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
Use a for statements to print all the elements in the array. Hint: review pointers as parameters.
*/
void Homework::print_array(int array[], int size) {

	for (int i = 0; i < size; i++) {

		cout << array[i] << " ";
	}	
	cout << "\n";
}

/*Create a function selection_sort that receives as parameters an array of integers and the array size,
and order the array element in descending order. Implement Selection Sort algorithm. 
It should be Selection Sort, not Bubble Sort, not Quick Sort, etc.
*/
void Homework::selection_sort(int array[], int size) {

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
int Homework::factorial(int number) {

	if (number == 0)	//base case
		return 1;		//base value
	else
		return number * factorial(number - 1);  //recursive problem
}
