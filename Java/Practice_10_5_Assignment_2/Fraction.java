package Practice_10_5_Assignment_2;

/**
 * @author Jason Avila-Soria
 * 
 * @version 1.0
 */
public class Fraction {
	private int top;
	private int bottom;
	private boolean positive;
	
	/**
	 * @apiNote constructor for default fraction being 1/1 since anything times 1 is itself.
	 */
	public Fraction() {
		top = 1;
		bottom = 1;
		positive = true;
	}
	/**
	 * 
	 * @param frac takes a string as input and constructs the top and bottom portion of the fraction after parsing the original string
	 */
	public Fraction(String frac) {
		top = 1;
		bottom = 1;
		positive = true;
		
		//buffer to hold parsed string
		String buffer[] = new String[2];
		
		//splits fraction at the slash and throws error if buffer is invalid: ex: frac = ./
		buffer = frac.split("/");
		if (buffer.length == 0 || frac == "") {
			throw new Error("Unkown fraction entered");
		}
		
		//true = top num
		boolean topOrBottom = true;

		//foreach string (only 2 anyways), check if negative and if they are
			//then parse to negative int.
		for (String k : buffer) {
			//just incase user enters //
			if (k == "" ) {
				throw new Error("Check input, no multiple operators allowed");
			}
			// if the string is negative then remove the negative symbol and check if the other contents are 0-9. if not throw an error, otherwise set the top or bottom int
				//to negative
			if (k.startsWith("-")) {
				positive = false;
				k = k.substring(1);	
				
				//check if 0-9
				for (int i = 0; i < k.length(); i++) {
					if (k.charAt(i) < 48 || k.charAt(i) > 57) {
						throw new Error("Not a number between 0-9!");
					}
				}
				if (topOrBottom) {
					top = -Integer.parseInt(k);
				}
				else if (!topOrBottom){
					bottom = -Integer.parseInt(k);
				}
			}
			else {
				//check 0-9, same as previous except for positive integers
				for (int i = 0; i < k.length(); i++) {
					if (k.charAt(i) < 48 || k.charAt(i) > 57) {
						throw new Error("Not a number between 0-9!");
					}
				}
				if (topOrBottom) {
					top = Integer.parseInt(k);
				}
				else if (!topOrBottom){
					bottom = Integer.parseInt(k);
				}
			}
			topOrBottom = false;
		}
		
		//checks if 0 denom
		if (bottom == 0) {
			throw new Error("Cannot divide by zero!");
		}
		
		//debug
	    //System.out.println("\n" + top + " " + bottom);
	}
	
	/**
	 * 
	 * @param frac1 first fraction to subtract from
	 * @param frac2 second fraction used to subtract
	 * @return returns the result of the operation as a string value
	 */
	public static String subtractFrac(Fraction frac1, Fraction frac2) {
		Fraction result = null;
		Fraction temp = null;
		//to handle two negative subtract
		String res1 = "";
		
		//init some fractions to help with subtracting
		try {
			result = new Fraction();
			temp = new Fraction();
		} catch (Error e) {
			System.out.println("Unable to make fraction");
		}
		
		//if the denom are the same then just do top - top, otherwise find common denominator and then subtract. 
		if (frac1.bottom == frac2.bottom) {
			result.bottom = frac1.bottom;
			result.top = (frac1.top - frac2.top);
		}
		else {
			temp.top = frac1.top * frac2.bottom;
			temp.bottom = frac1.bottom * frac2.bottom;
			result.top = frac2.top * frac1.bottom;
			result.bottom = frac2.bottom * frac1.bottom;
			
			result.top = temp.top - result.top;
			
			//incase fraction is not in simplest form
			int gcd = gcd(result.top, result.bottom);
			result.top /= gcd;
			result.bottom /= gcd;
			
		}
		//return string of the fraction top and bottom
		String res = new String(result.top + "/" + result.bottom);
		res = zeroChecker(result);
		res = strChecker(res);
		

		return res;
	}
	/**
	 * 
	 * @param frac1 fraction 1 to add
	 * @param frac2 ffraction 2 to add
	 * @return returns string of final fraction that was added
	 */
	public static String addFrac(Fraction frac1, Fraction frac2) {
		Fraction result = null;
		Fraction temp = null;
		
		//temp variables initilized
		try {
			result = new Fraction();
			temp = new Fraction();
		} catch (Error e) {
			System.out.println("Unable to make fraction");
		}
		
		//if the denom are the same then just add top parts, otherwise find common denom and then add
		if (frac1.bottom == frac2.bottom) {
			result.bottom = frac1.bottom;
			result.top = (frac1.top + frac2.top);
		}
		else {
			temp.top = frac1.top * frac2.bottom;
			temp.bottom = frac1.bottom * frac2.bottom;
			result.top = frac2.top * frac1.bottom;
			result.bottom = frac2.bottom * frac1.bottom;
			result.top += temp.top;
			
			//incase frac is not in simplest form
			int gcd = gcd(result.top, result.bottom);
			result.top /= gcd;
			result.bottom /= gcd;
			
		}
		//return string of final fraction added
		String res = new String(result.top + "/" + result.bottom);
		res = zeroChecker(result);
		res = strChecker(res);
		
		return res;
	}
	/**
	 * 
	 * @param frac1 fraction 1 to multiply
	 * @param frac2 fraction 2 to multiply
	 * @return returns string of final product.
	 */
	public static String multiFrac(Fraction frac1, Fraction frac2) {
		Fraction result = null;
		//init result variable.
		try {
			result = new Fraction();
		} catch (Error e) {
			System.out.println("Unable to make fraction");
		}
		
		//multiply fraction
		result.bottom = frac1.bottom * frac2.bottom;
		result.top = frac1.top * frac2.top;
		
		//incase fraction is not in simplest form
		int gcd = gcd(result.top, result.bottom);
		result.top /= gcd;
		result.bottom /= gcd;
			
		//return string of final product of the two fractions
		String res = new String(result.top + "/" + result.bottom);
		res = zeroChecker(result);
		res = strChecker(res);

		return res;
	}
	/**
	 * 
	 * @param frac1 first fraction to divide
	 * @param frac2 second fraction to divide by
	 * @return returns string of final division
	 */
	public static String diviFrac(Fraction frac1, Fraction frac2) {
		Fraction result = null;
		//init variable to return
		try {
			result = new Fraction();
		} catch (Error e) {
			System.out.println("Unable to make fraction");
		}
		//cross multiply
		result.bottom = frac1.bottom * frac2.top;
		result.top = frac1.top * frac2.bottom;
		
		//incase fraction is not in simplest form
		int gcd = gcd(result.top, result.bottom);
		result.top /= gcd;
		result.bottom /= gcd;
			
		//returns string of final operation
		String res = new String(result.top + "/" + result.bottom);
		res = zeroChecker(result);
		res = strChecker(res);

		return res;
	}
	/**
	 * 
	 * @param frac1 fraction to get reciprocal of
	 * @return
	 */
	public static String reciFrac(Fraction frac1) {
		Fraction result = null;;
		//init variable to return
		try {
			result = new Fraction();
		} catch (Error e) {
			System.out.println("Unable to make fraction");
		}
		//get reciprocal
		result.top = frac1.bottom;
		result.bottom = frac1.top;
		
		//try catch to check if the reciprocal is any x/0... throws an error and returns the reciprocal is not computable
		try {
			String result1 = zeroChecker(result);
		} catch(Error e) {
			System.out.println(e);
			return "not computed";
		}
		
		//incase reciprocal is not in simplest form
		int gcd = gcd(result.top, result.bottom);
		result.top /= gcd;
		result.bottom /= gcd;
		
		//returns string of reciprocal
		String res = new String(result.top + "/" + result.bottom);
		res = zeroChecker(result);
		res = strChecker(res);

		return res;
	}
	/**
	 * 
	 * @param frac1 fraction 1 to be compared
	 * @param frac2 fraction 2 to be compared
	 * @return returns true if they are the same fraction.
	 */
	public static boolean compareFrac(Fraction frac1, Fraction frac2) {
		
		//first simplify frac 1 then simplify frac 2 then compare if they are the same fraction.
		int gcd = gcd(frac1.top, frac1.bottom);
		frac1.top /= gcd;
		frac1.bottom /= gcd;
		
		gcd = gcd(frac2.top, frac2.bottom);
		frac2.top /= gcd;
		frac2.bottom /= gcd;
		
		if (frac1.top == frac2.top) {
			if (frac1.bottom == frac2.bottom) {
				return true;
			}
		}
		return false;		
	}
	
	/**
	 * 
	 * @param num1 number one to get gcd with
	 * @param num2 number two to get gcd with
	 * @return returns the gcd of num1 and num2
	 */
	public static int gcd(int num1, int num2) {		
	
		while (num2 != 0) {
			int r  = num1 % num2;
			num1 = num2;
			num2 = r;
		}
		
		return num1;
	}
	/**
	 * 
	 * @param frac1 inputs string to check if its negative. Used to check if a fraction is negative after an operation. 
	 * @return returns original string if not negative, otherwise moves the negative sign to the beginning of the fraction.
	 */
	private static String strChecker(String frac1) {
		String result = "";
		
		//check if negative, if it is then start the new string with a negative symbol and fill the rest of the string with what was passed in
		if (frac1.contains("-")) {
			result += "-";
			for (int i = 0; i < frac1.length(); i++) {
				if (frac1.charAt(i) != '-') {
					result += frac1.charAt(i);
				}
			}
		}
		else {
			result = frac1;
		}
		
		return result;
	}
	/**
	 * 
	 * @param frac1 Fraction to be compared if it is 0 in numerator or denominator. Throws an error if denom == 0 since you cannot divide by 0.
	 * @return returns parsed string of original fraction if no 0 in numerator/denominator
	 * If the numerator is 0 then returns 0. but also simplifies fraction if the numerator and denominator are the same number by returning 1/1.
	 */
	private static String zeroChecker(Fraction frac1) {
		Fraction temp = new Fraction();
		
		
		if (frac1.top == 0) {
			return "0";
		}
		else if (frac1.bottom == 0) {
			throw new Error("Cannot divide by zero!");
		}
		//returns the right value of simplified fraction either negative or positive.
		else if (Math.abs(frac1.top) == Math.abs(frac1.bottom)) {
			if (frac1.top < 0) {
				if (frac1.bottom < 0) {
					return "1/1";
				}
				else {
					return "-1/1";
				}
			}
			return "1/1";
		}
		else {
			String result = new String(frac1.top + "/" + frac1.bottom);
			return result;
		}
		
	}
}
