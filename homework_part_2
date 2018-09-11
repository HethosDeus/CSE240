/**

* DESCRIPTION:  File for Homework Part 2.  This file is provided in part
by the course and modified accordingly.

* Assnigment 2 for CSE240

* @author Adam Clifton

* @version 2018.09.04.

*/
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct patron {
	char last_name[30];
	char first_name[30];
};

struct theatre_seating {
	struct patron **seating;
	int rows;
	int cols;
};

/*Assign the default string "***" to both variables, last_name and first_name.
*/
void patron_init_default(struct patron *p) {

	strcpy(p->first_name, "***");
	strcpy(p->last_name, "***");
}

/*Use the strtok function to extract first name and last name from the variable patron,
then assign them to each instance variable of the patron structure.
An example of the input string is:  David/Johnson
*/
void patron_init(struct patron *p, char *info) {

	strcpy(p->first_name, strtok(info, "/")); //copy user string input (at *p), split at '/' for first name and last name
	strcpy(p->last_name, strtok(NULL, "/"));
}

/* It prints the initial character of the first name, a period, the initial character of the last name, and a period.
An example of such string for the patron David Johnson is:  D.J.
*/
void patron_to_string(struct patron *p) {

	printf("%c.%c. ", p->first_name[0], p->last_name[0]);
}


/* It instantiates a two-dimensional array of the size "rowNum" by "columnNum" specified by the parameters inside the struct t.
Then it initializes each patron element of this array using the patron_init_default function.
So, each patron will have default values for its instance variables.
*/
void theatre_seating_init(int rowNum, int columnNum, struct theatre_seating *t) {

	t->rows = rowNum;
	t->cols = columnNum;

	t->seating = (struct patron**)malloc(rowNum * sizeof(struct patron*));

	for (int r = 0; r < rowNum; r++) { //rows
		t->seating[r] = (struct patron*)malloc(columnNum * sizeof(struct patron));
	}

	for (int r = 0; r < rowNum; r++) {
		for (int c = 0; c < columnNum; c++) { //columns
			struct patron sit;
			patron_init_default(&sit);
			t->seating[r][c] = sit;
			//	patron_init_default(&t->seating[r][c]);
		}
	}
}


/*The function attempts to assign the "p" to the seat at "row" and "col" (specified by the parameters of this function).
If the seat has a default patron, i.e., a patron with the last name "***" and the first name "***", then we can assign
the new patron "p" to that seat and the method returns true. Otherwise, this seat is considered to be taken by someone
else, the method does not assign the patron and return 0 (false).
*/
int assign_patron_at(int row, int col, struct theatre_seating *t, struct patron* p) {

	if ((strcmp(t->seating[row][col].first_name, "***")) == 0 &&
		(strcmp(t->seating[row][col].last_name, "***")) == 0) {
		t->seating[row][col] = *p;
		return 1;
	}
	else
		return 0;
}

/*The function checks if the parameters row and col are valid. If at least one of the parameters "row" or "col"
is less than 0 or larger than the last index of the array (note that the number of rows and columns can be different),
then it return 0 (false). Otherwise it returns 1 (true).
*/
int check_boundaries(int row, int col, struct theatre_seating *t) {

	if (row < 0 || col < 0 || row > sizeof(t->seating) || col > sizeof(t->seating[0])) {
		return 0;
	}
	else {
		return 1;
	}
}

/*It prints information of the "seating". It should show the list of patrons assigned to the seating using
the patron_to_string function (it shows initials of each patron).
*/
void theatre_seating_to_string(int rowNum, int columnNum, struct theatre_seating *t) {//THIS IS THE PROBLEM, EVERYTHING ELSE WORKS LIKE ITS SUPPOSED TO.

	printf("The current seating:\n");
	printf("--------------------\n");


	for (int r = 0; r < rowNum; r++) {
	for (int c = 0; c < columnNum; c++) {
	patron_to_string(&t->seating[r][c]);
	printf(" ");
		}
		printf("\n");
	}
}


void main() {

	struct theatre_seating theatre_seating;
	struct patron temp_patron;
	int row, col, rowNum, columnNum;
	char patron_info[30];
	// Ask a user to enter a number of rows for a theatre seating
	printf("Please enter a number of rows for a theatre seating.");
	scanf("%d", &rowNum);
	// Ask a user to enter a number of columns for a theatre seating
	printf("Please enter a number of columns for a theatre seating.");
	scanf("%d", &columnNum);
	// theatre_seating
	theatre_seating_init(rowNum, columnNum, &theatre_seating);
	printf("Please enter a patron information or enter \"Q\" to quit.");
	/*** reading a patron's information ***/
	scanf("%s", patron_info);
	/* we will read line by line **/
	while (!(strcmp(patron_info, "Q") == 0)) {
		printf("\nA patron information is read.");
		// printing information.
		printf("%s", patron_info);
		// patron
		patron_init(&temp_patron, patron_info);
		// Ask a user to decide where to seat a patron by asking
		// for row and column of a seat
		printf("Please enter a row number where the patron wants to sit.");
		scanf("%d", &row);
		printf("Please enter a column number where the patron wants to sit.");
		scanf("%d", &col);
		// Checking if the row number and column number are valid
		// (exist in the theatre that we created.)
		if (check_boundaries(row, col, &theatre_seating) == 0) {
			printf("\nrow or column number is not valid.");
			printf("A patron %s %s is not assigned a seat.", temp_patron.first_name, temp_patron.last_name);
		}
		else {
			// Assigning a seat for a patron
			if (assign_patron_at(row, col, &theatre_seating, &temp_patron) == 1) {
				printf("\nThe seat at row %d and column %d is assigned to the patron", row, col);
				patron_to_string(&temp_patron);
				theatre_seating_to_string(rowNum, columnNum, &theatre_seating);
			}
			else {
				printf("\nThe seat at row %d and column %d is taken.", row, col);
			}
		}
		// Read the next patronInfo
		printf("Please enter a patron information or enter \"Q\" to quit.");
		/*** reading a patron's information ***/
		scanf("%s", patron_info);
	}
}
