/**
* PART 2: Classes, objects, and Arrays
* DESCRIPTION: contains information about patron input information from the Assignment.java class
*	default parameters of '***' (constructor Patron()),
*	splits patron input of first and last name with '/' parameter (Patron(String patronInfo)),
*	gets first and last name (constructors getFirstName and getLastName), and 
*	displays first character of patron name input in 'firstInitial.lastInitial' form (toString)
*	
* Patron for CSE240
*
* @author Adam Clifton (akclifto@asu.edu)
* @version 2018.08.25
*/
public class Patron {

	String firstName;
	String lastName;
	
/* Patron() method constructs a Patron object by assigning the default string '***' to both instance variables, lastName and firstName.
 * */ 	
	public Patron () {
		
		lastName = "***";
		firstName = "***";
	}
	
/*Patron (String patronInfo) constructs a Paton object using the string containing patron's info.  Use the split metho of the String class to extract
 * first and last name, then assign them to each instance variblae of the Patron class.
 *
 * splits firstName and lastName from single entry using the scanner input, separator denotes as "/" 
 * */
	// constructor chaining from Patron()
	public Patron (String patronInfo) {
		
		//patronInfo = null;  //not used
				
		while (patronInfo != null) {
			String[] strSplit = patronInfo.split("/");
			
			firstName = strSplit[0];
			lastName = strSplit[1];
		//	PatronInfo = firstName + " " + lastName;  //not used
			
			return;
		}
	}
	
	//getter last name
	public String getLastName() {
		
		return lastName;
	}

	//getter first name
	public String getFirstName() {
		
		return firstName;
	}
	
	//toString to output just the initial of the name entries with periods after the first and last initial (eg, 'M.M.')
	public String toString() {
		
		String res = getFirstName().charAt(0) + "." + getLastName().charAt(0) + ".";
		return res;
	}
	
}
