/**
* PART 2: Classes, objects, and Arrays
* DESCRIPTION:  TheatreSeating Class assigns patrons to seating by row and column (TheatreSeating), 
* 	returns the patron at the seat assignment (getPatronAt), 
* 	assigns patron to a row and column (assignPatronAt), 
* 	checks boundaries to make sure they are within the alotted theatre seating, and tells you otherwise (checkBoundaries), and 
* 	prints out the assigned seating with the initial of the patron at their alotted seat  and '*.*' for empty seats (toString)
* 
* TheatreSeating for CSE240
*
* @author Adam Clifton
* @version 2018.08.25
*/
public class TheatreSeating {

	private Patron [][] seating;
	
	/*This instantiates a 2D array of the size 'rowNum' by 'columnNum' specified by the 
	 * parameters.  Then it initializes each patron element of this array using the constructor 
	 * of the class Patron without any parameter.  So, each patron will have
	 * default values for its instance variables.
	 * */
	public TheatreSeating (int rowNum, int columnNum) {
		
		seating = new Patron [rowNum][columnNum];
			
		for (int r = 0; r <rowNum; r++) {
			
			for (int c = 0; c < columnNum; c++) {
				seating[r][c] = new Patron();
			}
		}
	}
	
	//retrieves patron seating position from public TheatreSeating
	private Patron getPatronAt(int row, int col) {
		
		return seating[row][col];
	}
	
	/*The method attempts to assign the "tempPatron" to the seat at "row" and "col" (specified
	 * by the parameters of this method).  If the seat has a default patron, ie, a patron with 
	 * the last name "***" and first name "***", then we can assign the new patron "tempPatron"
	 * to that seat and the method returns true.  Otherwise, this seat is considered to be taken by
	 * someone else, the method does not assign the patron and returns false
	 * */
	public boolean assignPatronAt (int row, int col, Patron tempPatron) {
		
		if (seating[row][col].getFirstName().equals("***") && seating[row][col].getLastName().equals("***")) {
			seating[row][col] = tempPatron;
			return true;
		} else {
			//System.out.println("Seat is already taken.");
			return false;
		}
	}

	/* The method check if the parameters row and col are valid.  If at least one of the 
	 * parameters row or col is less than 0 or larger than the last index of the array
	 * (note that the number of rows and cols can be different) then it returns false.
	 * otherwise, it returns true
	 * */
	public boolean checkBoundaries (int row, int col) {
		
		if (col < 0 || row < 0 || col > seating.length || row > seating.length) { 
			//System.out.println("seating OOB");  //for testing
			return false;
			
		} else {
			return true;
		}
	}
	
	
	/* Returns a String containing information of the 'seating'.  If should show the list
	 * of patrons assigned to the seating using the toString method of the class
	 * Patron(it shows the initials of each patron)*/ 
	@Override
	public String toString() {
		
		String seats = "The current seating\n ";
		seats += "--------------------\n";
		for (int r = 0; r < seating.length; r++) {
			
			for (int c = 0; c < seating[r].length; c++) {
				
				seats += seating[r][c].getFirstName().charAt(0) + "."   
					   + seating[r][c].getLastName().charAt(0) + ". ";
			} 
			seats += "\n";
		} 
		return seats;
	}
	
	
}
