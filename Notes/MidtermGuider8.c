#include <stdio.h>

//In the following code :
int main() {
	int var = 10;
	int *p;
	p = &var;

	printf("\n %p", &var);     // %p is a memory address.  this is printing the memory address of var
	printf("\n %p", p);        // this is printing the memory address of p, which points to var (so its the same as var)
	printf("\n %p", &p);       // this prints memory address of p, not its pointer
	printf("\n %p", p);        // this is printing the memory address of p, which points to var (so its the same as var)
	printf("\n %d", var);      // this prints int value of var, which is 10
	printf("\n %d", *p);       // this prints int value of pointer p, which points to var, which is 10
	printf("\n %d", *(&var));  // this prints int value of the pointer referencing var, which is p, which points to var, which is 10
} 
//Could you explain what is being printed for each printf instruction 
