package Practice_10_5_Assignment_2;

import java.util.*;
/**
 * @@author Jason Avila-Soria
 * @version 1.0
 * Class to test Fraction class
 */
public class FracTest {
	/**
	 * Main method to test all operations of the Fraction class
	 * 
	 */
	public static void main(String[] args) {
		//declare two fractions and init scanner for input as well as two strings that will be used for fractions
		Fraction frac1 = null;
		Fraction frac2 = null;
		
		Scanner in = new Scanner(System.in);		
		String strIn = "";
		String strIn2 = "";
		
		
		//main menu loop continue if not Q:
		System.out.printf("Type Q at anytime to quit an operation\n\n*****Menu*****\n");
		System.out.printf("1.) Add 2 fractions\n2.) Subract 2 fractions\n3.) Multiply 2 fractions\n4.) Divide 2 fractions\n5.) Reciprocal of a fraction\n6.) Compare 2 fractions\n");
		
		do {
	    	System.out.print("Please enter your selection or type M for menu: ");
			// selection:
			strIn = in.nextLine();
			
			//first if is addition, takes in two inputs and makes new Fraction vairables based off the inputs.
			if (strIn.equals("1")) {
				
				//enter first fraction, if q continue
				System.out.println("Please enter your first fraction: ");
				strIn = in.nextLine();
				if (strIn.equalsIgnoreCase("Q")) {
					System.out.println("*****Operation cancelled*****");
					continue;
				}
				try {
					frac1 = new Fraction(strIn);
				}catch (Error e) {
					System.out.println(e + "\n"); continue;
				}
				
				//input second fraction, continue if q
				System.out.println("Please enter your second fraction: ");
				strIn2 = in.nextLine();
				if (strIn2.equalsIgnoreCase("Q")) {
					System.out.println("*****Operation cancelled*****");
					continue;
				}
				try {
					frac2 = new Fraction(strIn2);
				}catch (Error e) {
					System.out.println(e + "\n"); continue;
				}
				
				//get result from method and print result
				String result = Fraction.addFrac(frac1, frac2);
				System.out.println("Adding " + strIn + " and " + strIn2 + " = " + result + "\n");
		    }
			//used for subtraction
		    else if (strIn.equals("2")) {
		    	
		    	//enter frac1, continue if q
		    	System.out.println("Please enter your first fraction: ");
				strIn = in.nextLine();
				if (strIn.equalsIgnoreCase("Q")) {
					System.out.println("*****Operation cancelled*****");
					continue;
				}
				try {
					frac1 = new Fraction(strIn);
				}catch (Error e) {
					System.out.println(e + "\n"); continue;
				}
				
				//enter frac2, continue if q
				System.out.println("Please enter your second fraction: ");
				strIn2 = in.nextLine();
				if (strIn2.equalsIgnoreCase("Q")) {
					System.out.println("*****Operation cancelled*****");
					continue;
				}
				try {
					frac2 = new Fraction(strIn2);
				}catch (Error e) {
					System.out.println(e + "\n"); continue;
				}
				
				//get result from method and print to screen
				String result = Fraction.subtractFrac(frac1, frac2);
				System.out.println("Subtracting " + strIn + " and " + strIn2 + " = " + result + "\n");
		    }
			//used for multiplication
		    else if (strIn.equals("3")) {
		    	//enter frac1, continue if q
		    	System.out.println("Please enter your first fraction: ");
				strIn = in.nextLine();
				if (strIn.equalsIgnoreCase("Q")) {
					System.out.println("*****Operation cancelled*****");
					continue;
				}
				try {
					frac1 = new Fraction(strIn);
				}catch (Error e) {
					System.out.println(e + "\n"); continue;
				}
				
				//enter frac2, continue if q
				System.out.println("Please enter your second fraction: ");
				strIn2 = in.nextLine();
				if (strIn2.equalsIgnoreCase("Q")) {
					System.out.println("*****Operation cancelled*****");
					continue;
				}
				try {
					frac2 = new Fraction(strIn2);
				}catch (Error e) {
					System.out.println(e + "\n"); continue;
				}
				
				//get string result and display to screen
				String result = Fraction.multiFrac(frac1, frac2);
				System.out.println("Multiplying " + strIn + " and " + strIn2 + " = " + result + "\n");
		    }
			//used for division
		    else if (strIn.equals("4")) {
		    	//enter frac1, continue if q
		    	System.out.println("Please enter your first fraction: ");
				strIn = in.nextLine();
				if (strIn.equalsIgnoreCase("Q")) {
					System.out.println("*****Operation cancelled*****");
					continue;
				}
				try {
					frac1 = new Fraction(strIn);
				}catch (Error e) {
					System.out.println(e + "\n"); continue;
				}
				
				//enter frac2, contniue if q
				System.out.println("Please enter your second fraction: ");
				strIn2 = in.nextLine();
				if (strIn2.equalsIgnoreCase("Q")) {
					System.out.println("*****Operation cancelled*****");
					continue;
				}
				try {
					frac2 = new Fraction(strIn2);
				}catch (Error e) {
					System.out.println(e + "\n"); continue;
				}
				
				//get string result and display to screen
				String result = Fraction.diviFrac(frac1, frac2);
				System.out.println("Dividing " + strIn + " and " + strIn2 + " = " + result + "\n");
		    }
			//used for reciprocal
		    else if (strIn.equals("5")) {
		    	//enter fraction to get reciprocal of, continue if q
		    	System.out.println("Please enter your fraction: ");
				strIn = in.nextLine();
				if (strIn.equalsIgnoreCase("Q")) {
					System.out.println("*****Operation cancelled*****");
					continue;
				}
				try {
					frac1 = new Fraction(strIn);
				}catch (Error e) {
					System.out.println(e + "\n"); continue;
				}
				
				//get string result and display to screen
				String result = Fraction.reciFrac(frac1);
				System.out.println("The reciprocal of " + strIn + " is " + result + "\n");
				
		    }
			//used for comparing two fractions
		    else if (strIn.equals("6")) {
		    	//enter frac1, continue if q
		    	System.out.println("Please enter your first fraction: ");
				strIn = in.nextLine();
				if (strIn.equalsIgnoreCase("Q")) {
					System.out.println("*****Operation cancelled*****");
					continue;
				}
				try {
					frac1 = new Fraction(strIn);
				}catch (Error e) {
					System.out.println(e + "\n"); continue;
				}
				
				//enter second fraction, continue if q
				System.out.println("Please enter your second fraction: ");
				strIn2 = in.nextLine();
				if (strIn.equalsIgnoreCase("Q")) {
					System.out.println("*****Operation cancelled*****");
					continue;
				}
				try {
					frac2 = new Fraction(strIn2);
				}catch (Error e) {
					System.out.println(e + "\n"); continue;
				}
				
				//result true if equal, false if not equal and display to screen
				boolean result = Fraction.compareFrac(frac1, frac2);
				if (!result) {
					System.out.println("The fraction " + strIn + " and the fraction " + strIn2 + " are not equal.\n");
				}
				else {
					System.out.println("The fraction " + strIn + " and the fraction " + strIn2 + " are equal.\n");
				}
		    }
			//used to terminate program
		    else if (strIn.equalsIgnoreCase("Q")) {
		    	//close scanner and exit
		    	in.close();
		    	System.out.println("\nProcess finished.");
				System.exit(0);
		    }
			//display menu
			else if (strIn.equalsIgnoreCase("M")) {
				System.out.printf("\nType Q at anytime to quit an operation\n\n*****Menu*****\n");
				System.out.printf("1.) Add 2 fractions\n2.) Subract 2 fractions\n3.) Multiply 2 fractions\n4.) Divide 2 fractions\n5.) Reciprocal of a fraction\n6.) Compare 2 fractions\n\n");
			}
			//if none of the above then put input in again.
		    else {
		    	System.out.println("Invalid selection, please try again.\n");
		    }
		} while (true);
	}}
