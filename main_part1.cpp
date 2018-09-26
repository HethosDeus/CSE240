/**
* Description:  Main file for part one of the Homework week 4.  This code is given in full. 
* Assignment 3 for CSE240

* @author Adam Clifton
* @version 2018.09.07
*/

#include <iostream>
#include "homework.h"
#pragma once
using namespace std;

int main() {
	int a[10] = { 3, 5, 6, 8, 12, 13, 16, 17, 18, 20 };
	int b[6] = { 18, 16, 19, 3 ,14, 6 };
	int c[5] = { 5, 2, 4, 3, 1 };
	Homework h;
	// testing initialize_array
	h.print_array(a, 10); // print: 3, 5, 6, 8, 12, 13, 16, 17, 18, 20
	h.initialize_array(a, 10);
	h.print_array(a, 10); // print: 0, 1, 0, 1, 0, 1, 0, 1, 0, 1

	// testing initialize_array
	h.print_array(b, 6); // print: 18, 16, 19, 3 ,14, 6
	h.selection_sort (b, 6);
	h.print_array(b, 6); // print: 19, 18, 16, 14, 6, 3 

	// testing factorial
	cout << "Factorial of 5 = " << h.factorial (5) <<endl; //print: 120 
	c[0] = h.factorial(c[0]);
	c[1] = h.factorial(c[2]);
	h.print_array(c, 5); // print: 120, 24, 4, 3, 1 

	return 0;
}
