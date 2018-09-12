import java.util.Scanner;
/**
* PART 2: Classes, objects, and Arrays
* DESCRIPTION:  This is the main method class that uses the TheatreSeating and Patron classes:
* 	to store seating and patron information using console inputs.  It assigned theatre seat size, adds patrons, add patrons to seats, checks parameters of 
* 	seating of patrons and outputs assignments or issues/errors accordingly.  This class was provided in the homework assigned IN FULL 	
*
* Assignment for CSE240
*
* @author Adam Clifton
* @version 2018.08.25
*/
public class Assignment {
	
	public static void main(String[] args) {
		
		TheatreSeating theatreSeating;
		Patron tempPatron;
		int row, col, rowNum, columnNum;
		String patronInfo;
		Scanner scan = new Scanner (System.in);
		
		//Ask a user to enter a number of rows for a theatre seating
		System.out.println ("Please enter a number of rows for a theatre seating.");
		rowNum = scan.nextInt();
		
		//Ask a user to enter a number of columns for a theatre seating
		System.out.println("Please enter a number of columns for a theatre seating.");
		columnNum = scan.nextInt();
		
		//instantiate a TheatreSeating object
		theatreSeating = new TheatreSeating (rowNum, columnNum);
		
		System.out.println("Please enter a patron information or enter \"Q\" to quit.");
		
		/*** reading a patron's information ***/
		patronInfo = scan.next();
		
		/* we will read line by line **/
		while (!patronInfo.equalsIgnoreCase("Q")) {
			System.out.println("\nA patron information is read.");
			//printing information read from file.
			System.out.println(patronInfo);
			
			//creating a patron object using the patron information from a user
			tempPatron = new Patron(patronInfo);
			
			//Ask a user to decide where to seat a patron by asking for row and column of a seat
			System.out.println("Please enter a row number where the patron wants to sit.");
			row = scan.nextInt();
			
			System.out.println("Please enter a column number where the patron wants to sit.");
			col = scan.nextInt();
			
				//Checking if the row number and column number are valid 
					// (exist in the theatre that we created.)
			
			if (theatreSeating.checkBoundaries(row, col) == false) {
				System.out.println("\nrow or column number is not valid.");
				System.out.println("A patron " + tempPatron.getFirstName() + " " + tempPatron.getLastName() + " " + "is not assigned a seat.");
			} else {
				//Assigning a seat for a patron
				 if (theatreSeating.assignPatronAt(row,col,tempPatron) == true){ 
					System.out.println("\nThe seat at row " + row +" and column " + col + " is assigned to the patron " + tempPatron.toString());
					System.out.println(theatreSeating); 
				 } else {
					 System.out.println("\nThe seat at row " + row + " and column " + col + " is taken.");  
				 }
			}
				
			// Read the next patronInfo 
			System.out.println("Please enter a patron information or enter \"Q\" to quit."); 
			/*** reading a patron's information ***/
			patronInfo = scan.next(); 
		}
	}	
}
