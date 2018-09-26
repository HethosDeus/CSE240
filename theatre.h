/**
* Description:This is the header file for homeowork week 4 part 1.  This file
provides class definitions for the main_part1.cpp and homework.cpp files
*
*
* @author Adam Clifton
* @version 2018.09.07
*/
#pragma once
#ifndef THEATRE_H
#define THEATRE_H


#include "patron.h"


class Theatre {
private:
	Patron **seating;
	int globalRow, globalColumn; //used globally in theatre.cpp for dimensions

public:
	Theatre(int rowNum, int columnNum);
	//~Theatre();   //no garbage collector needed for assignment
	Patron* getPatronAt(int row, int col);
	bool assignPatronAt(int row, int col, Patron *tempPatron);
	bool checkBoundaries(int row, int col);
	char* toString();

};

#endif // !THEATRE_H
