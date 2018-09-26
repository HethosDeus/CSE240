/**
* Description:This is the main file for homework week 4 part 2.  This file
is provided by the homework assignment.
* Completion time: 1 hour to copy and debug
*
* @author Adam Clifton
* @version 2018.09.07
*/
#include <iostream>
#include <string>
#include "theatre.h"

using namespace std;


int main() { //changes from void main to int main()
	Theatre* theatre;
	Patron* tempPatron;
	int row, col, rowNum, columnNum;
	char patronInfo[30];

	// Ask a user to enter a number of rows for a theatre seating
	cout << "Please enter a number of rows for a theatre seating.";
	cin >> rowNum;
	
	// Ask a user to enter a number of columns for a theatre seating
	cout << "Please enter a number of columns for a theatre seating.";
	cin >> columnNum;

	// theatre_seating
	theatre = new Theatre(rowNum, columnNum);	
	cout <<"Please enter a patron information or enter \"Q\" to quit.";
	
	/*** reading a patron's information ***/
	cin >> patronInfo;

	/* we will read line by line **/
	while ((strcmp(patronInfo, "q") != 0 && strcmp(patronInfo, "Q") != 0)) {
		cout << "\nA patron information is read.";
		// printing information.
		cout << patronInfo;
		// patron
		tempPatron = new Patron (patronInfo);
		
		// Ask a user to decide where to seat a patron by asking
		// for row and column of a seat 
		cout << "\nPlease enter a row number where the patron wants to sit.";
		cin >> row;
		cout << "\nPlease enter a column number where the patron wants to sit.";
		cin >> col;
		
		// Checking if the row number and column number are valid 
		// (exist in the theatre that we created.)
		if ((*theatre).checkBoundaries(row, col) == false) {
			cout << "\nrow or column number is not valid.";
			cout << "A patron" << (*tempPatron).getFirstName() << " " <<
				(*tempPatron).getLastName() << " is not assigned a seat.";
		} else {
			
		// Assigning a seat for a patron
			if ((*theatre).assignPatronAt(row, col, tempPatron) == true){
				cout <<"\nThe seat at row "<< row << " and column " << col <<
					" is assigned to the patron, " << (*tempPatron).toString();
				cout << "\n" << (*theatre).toString();
			} else 
			{
				cout <<"\nThe seat at row " << row << " and column " << col << " is taken.";
			}
		}
		// Read the next patronInfo
		cout <<"\nPlease enter a patron information or enter \"Q\" to quit.";
		
		/*** reading a patron's information ***/
		cin >>patronInfo;
	}  

}
