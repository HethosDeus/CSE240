/*
• Write a C program that, given an array a[ ] with size n and another number x, determines whether or not there exist two elements in a [ ] whose sum is exactly x.
It returns 0 (the two elements do not exist) or 1 (the two elements exist).
*/
#include <stdio.h>

int CheckSum(int a[], int n, int x)
{
	int ind = 0; // index of first element
	int jind = 9; //index of last element

	while (ind < jind)
	{
		// check if the sum of elements at index i and j equals val, if yes we are done
		if (a[ind] + a[jind] == x)
		{
			printf("sums: %d + %d \n", a[ind], a[jind]);
			return a[ind];
		}
		// else if sum if more than val, decrease the sum.
		else if (a[ind] + a[jind] > x) {
			jind--;
		}
		// else if sum is less than val, increase the sum.
		else {
			ind++;
		}
	}
	// failed to find any such pair..return false. 
	printf("there are no two sums equals to the value you seek.");
	return 0;
}

int main()
{
	int a[10] = { 1,2,3,4,5,6,7,8,9,10 };
	int n = 10, x = 13;
	int back;
	printf("%d \n", sizeof(a)); //prints out 40 for some reason...
	back = CheckSum(a, n, x);

}


/*
• Write a C++ program that, given an array of objects Ball (see question 5) named a[] of n objects, prints the id of all the objects with color==red.
*/

#include <iostream>
using namespace std;

class Ball
{
public:
	char *color;
	int id;

	void printRedIds(Ball arrayR[], int n) {
		for (int i = 0; i < n; i++) {
			if (strcmp(arrayR[i].color, "red"))
			{
				cout << "Red Balls \n Ball: " << i << "s id = " << arrayR[i].id << endl;
			}
		}
	}
};

int main() 
{
	int user;
	cout << "Enter a number \n";
	cin >> user;
	// code to run printRedIds -- will do later
}
