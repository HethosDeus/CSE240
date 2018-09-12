/**
* PART 1: Primitive types, searching, and recursion
* Create various methods to sort predetermined array of integers that includes Even/Odd Indexing and Selection Sort.
* Create a method to give the factorial of a predetermined array of integers.  
* 
* Homework for CSE240
*
* @author Adam Clifton
* @version 2018.08.21
*/
public class Homework {

/* This method places a 0s in even index positions and 1s in odd index positions.   
 * */
	public static void initializeArray (int [] array) {
		
		int evenIndex = 0;
		int oddIndex = 1;
			
/* for and if statement to iterate through even positions and assigned them to 0, then iterate through odd positions and assigning them to 1
*/	
		for (int i = 0; i <= array.length; i++) { 
			
			if (evenIndex < array.length) {
				array[evenIndex] = 0;
				evenIndex += 2;
			} 
			if (oddIndex < array.length) {
				array[oddIndex] = 1;
				oddIndex += 2;
			}	
		}	
	}
	
/* Print method output to console
 */
	public static void printArray(int [] array) {
		
		for (int i = 0; i < array.length; i++) {
			System.out.print(array[i] + " ");
		}  System.out.println("");
	}
	
/*selection sort method to sort in DESCENDING ORDER */
	public static void selectionSort (int [] array)
	{
		int maxIndex;
		
	//iterate through and find max index
		for (int i = 0; i < array.length; i++){  		
			maxIndex = i;
	//if integer at j is > integer of max index, j becomes max index.  if not, swap positions and shift
			for (int j = i + 1; j < array.length; j++){ 	
				if (array[j] > array[maxIndex]){
					maxIndex = j;	
				}
			}
				int temp = array[i];
				array[i] = array[maxIndex];
				array[maxIndex] = temp;
		}	
	}	
	
/* This method uses recursion to find the factorial of integers in a given array. */ 
	public static int factorial(int num) { 	//size of the problem, changes to static to test below in the main() function
		 							
		if (num == 0)	{		// stopping condition for base case
			return 1;			// return value base case
		} else {
			return num * factorial (num - 1); //return value subproblem		
		}
					
	}

/*main method output */
	public static void main (String [] arg) { 
		
		int [] a = {3, 5, 6, 8, 12, 13, 16, 17, 18, 20};
		int [] b = {18, 16, 19, 3 ,14, 6};
		int [] c = {5, 2, 4, 3, 1}; 
		
		//testing initializeArray 
		 	printArray(a); 						// print: 3, 5, 6, 8, 12, 13, 16, 17, 18, 20   
		 	initializeArray(a);   
		 	printArray(a);						// print: 0, 1, 0, 1, 0, 1, 0, 1, 0, 1 
		 
		// testing initializeArray 
			printArray(b); 						// print: 18, 16, 19, 3 ,14, 6   
		  	selectionSort (b);   
		   	printArray(b); 						// print: 19, 18, 16, 14, 6, 3 
		   	
		// testing factorial 
		   System.out.println (factorial (5)); 	//print: 120 
		   c[0] = factorial (c[0]);
		   c[1] = factorial (c[2]);
		   printArray(c);						// print: 120, 24, 4, 3, 1 
	}
}
