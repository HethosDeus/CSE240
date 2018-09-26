/**
* Description:This is the class implementation file for homeowork week 4 part 2,
for the main_part2.cpp and patron.cpp files.
* Assignment 3 for CSE240
*
* @author Adam Clifton (akclifto@asu.edu), Gonzalez-Sanchez
* @version 2018.09.07
*/
#define _CRT_SECURE_NO_WARNINGS
#include "patron.h"
#include <cstring>

using namespace std;

/*Constructs a Patron object by assigning the default string "***" 
to both instance variables, lastName and firstName.
*/
Patron::Patron() {

	strcpy(firstName, "***");
	strcpy(lastName, "***");
}

/*Constructs a Patron object using the string containing patron's info. 
Use the strtok function to extract first name and last name, then
assign them to each instance variable of the Patron class. 
An example of the input string is:  David/Johnson
*/
Patron::Patron(char* patronInfo) {
	//code strtok function
	strcpy(firstName, strtok(patronInfo, "/"));
	strcpy(lastName, strtok(NULL, "/"));
	
	//these don't work properly----------------------------
	/*
	char* name;
	name = strtok(patronInfo, "/");
	strcpy(firstName, name);
	name = strtok(NULL, "/");
	strcpy(lastName, name);
	*/

	/*
	char *token = strtok(firstName, "/");
	while (firstName != NULL) {
		strcpy(firstName, token);
		token = strtok(NULL, "/");
		strcpy(lastName, token);
	}*/
}

/*It should return the instance variable firstName.
*/
char* Patron::getFirstName() {
	return firstName;
}

/*It should return the instance variable lastName.
*/
char* Patron::getLastName() {
	return lastName;
}

/*It should constructor a string containing the initial character of the first name,
a period, the initial character of the last name, and a period, then it returns it.
An example of such string for the patron David Johnson is:  D.J.
*/
char* Patron::toString() {
		
	char temp[5] = {firstName[0], '.', lastName[0], '.', '\0'};
	char *seatInitials = new char[5];
	strcpy(seatInitials, temp);
	
	/*  this doesn't work properly: add extra chars-------------------------------
	char *seatInitials = new char[5];
		//seatInitials = {firstName[0], ".", lastName[0], "."};
		seatInitials[0] = firstName[0];
		seatInitials[1] = '.';
		seatInitials[2] = lastName[0];
		seatInitials[3] = '.';
		//seatInitials[4] = '\0';
		*/
	return seatInitials;
}
