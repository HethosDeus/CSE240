#include <stdio.h>

int* returnMe(int*); //* means this statement will return a pointer to an int (int*)

//returnType functionName (type arg1, type arg2)

int main(){

	int x = 10;
	int *p = &x;
	printf("%p: %p\n", p);
		
	printf("x: %d\n", x);
	
	p = returnMe(p);
	printf("p: %p\n", p); //this returns the memory address of a pointer
	
	return 0;
}

int* returnMe(int *pint){ //returning a pointer to int (*pint)
	return pint;
}


//SCENARIO:  passing two float pointers and trying to get the biggest float using functions
float* biggestTotal(float*, float*);

int main(){
	
	float x = 10.0;
	float y = 20.0
	
	printf("y: %p\n", &y);  //passing addresses, so use '&' to get the address
	
	float *b = biggestFloat(&x, &y);
	printf("b: %p\n", b);
	
	return 0;


}

float* biggestFloat (float *pfloat1, float *pfloat2){
	float *biggest;
	
	if (*pfloat1 > *pfloat2){
		biggest = pfloat1;
	}else{
		biggest = pfloat2;
	}
	return biggest;
}


//MALLOC APPLICATION scenario:  lets create a rectangular structure

#include <stdio.h>
#include <stdlib.h>   //need this to use malloc

typedef struct {
	int height;
	int width;
	
} rec_t;
} rec_t;

rec_t* new_rectangle (void);

int main(){
	
	rec_t *ptr; //declare pointer to rectangle
	ptr = new_rectangle();  //the memory is allocation below for the new rectangle, we can now use this pointer any way we want
	
	rec_t rectangle = *ptr;  // this dereferences the ptr and that gets us the structure to do whatever we want with it. like assign properties
	
	rectangle.width = 10;	//assigning props to rectangles.
	rectangle.height = 10;
	printf("height: %d, width:  %d\n", rectangle.height, rectangle.width); //print to screen
	
	free(ptr); //this frees up the memory allocation for the pointer when we are done using it to save space.
	
	return 0;
}

rec_t* new_rectangle (void){  //rec_t* means this is going to return a pointer to a rectangle type structure defined above
	rec_t *p = malloc(sizeof *p);
	return p;
}
