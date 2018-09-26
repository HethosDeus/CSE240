/**
* Description:This is the header file for homeowork week 4 part 2.  This file
provides class definitions for the patron.cpp, theatre.cpp and main_part2.cpp files
* 
*
* @author Adam Clifton
* @version 2018.09.07
*/
#pragma once
#ifndef PATRON_H
#define PATRON_H

class Patron {

private:
	char firstName[30];
	char lastName[30];
	
public:
	Patron();
	Patron(char* patronInfo);
	//~Patron();
	char* getLastName();
	char* getFirstName();
	char* toString();
};
#endif // !PATRON_H
