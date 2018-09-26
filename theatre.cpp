/**
* Description:This is the class implementation file for homeowork week 4 part 2,
for the main_part2.cpp and theatre.cpp files.
* Assignment 3 for CSE240
*
* @author Adam Clifto
* @version 2018.09.07
*/
#define _CRT_SECURE_NO_WARNINGS
#include "theatre.h"
#include <string>

using namespace std;

/*It instantiates a two-dimensional array of the size "rowNum" by "columnNum" specified by the parameters.
Then it initializes each patron element of this array using the constructor of the class Patron without any parameter.
So, each patron will have default values for its instance variables.  
*/
Theatre::Theatre(int rowNum, int columnNum) {
	globalRow = rowNum;
	globalColumn = columnNum;

	seating = new Patron *[rowNum];
	for (int i = 0; i < rowNum; i++) {
		seating[i] = new Patron[columnNum];
	}
}

/*It returns a patron at the indexes row and col (specified by the parameters of this method) of the array "seating". 
*/
Patron* Theatre::getPatronAt(int row, int col) {
	return &(this->seating[row][col]);  //
}

/*The method attempts to assign the "tempPatron" to the seat at "row" and "col" (specified by the parameters of this method).
If the seat has a default patron, i.e., a patron with the last name "***" and the first name "***",
then we can assign the new patron "tempPatron" to that seat and the method returns true. 
Otherwise, this seat is considered to be taken by someone else, the method does not assign the patron and returns false.
*/
bool Theatre::assignPatronAt(int row, int col, Patron *tempPatron) {

	if (strcmp(seating[row][col].getFirstName(), "***") ||
		strcmp(seating[row][col].getLastName(), "***")) {
			return false;
	}
	else {
		seating[row][col] = *tempPatron;
			return true;
	}
}

/*The method checks if the parameters row and col are valid. If at least one of the parameters "row"
or "col" is less than 0 or larger than the last index of the array (note that the number of rows and columns
can be different), then it returns false. Otherwise it returns true.
*/
bool Theatre::checkBoundaries(int row, int col) {
	
	if (row < 0 || col < 0 || row > globalRow || col > globalColumn) {
		return false;
	}
	else {
		return true;
	}
}

/*Returns a String containing information of the "seating". It should show the list of patrons assigned to the seating
using the toString method of the class Patron (it shows initials of each patron)
*/
char* Theatre::toString() {
	//create new char* to hold the toString
	char *res = new char[1000];
	strcpy(res, "The current seating:\n--------------------\n"); 

	for (int r = 0; r < globalRow; r++) { //rows
		for (int c = 0; c < globalColumn; c++) { //columns
			strcat(res, (seating[r][c].toString())); //strcat = concatenate string/char to append.
			strcat(res, " ");
		} 
		strcat(res, "\n");
	} 
	return res;
}
