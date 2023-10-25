package Practice_8_29;
//import java.util.Random;
import java.util.Scanner;


public class prime_numbers {
	public static void main(String[] args) {
		Scanner input = new Scanner(System.in);
		
		System.out.println("Please enter a number to print all prime numbers it and 1: ");
		prime(input.nextInt());
		
		input.close();
	}
	public static void prime(int n) {
		
	    System.out.print("\nThe prime numbers are:");
	    if (n >= 2) {
	    	//base case for 2
	        System.out.print(" 1 2");
	        
	        for (int i = 3; i <= n; i++) {
	        	//used trigger if a number is not prime
	            boolean isPrime = true;
	            for (int j = 2; j < i; j++) {
	            	//if the number is divisible by anything other than 1 and itself
	            		//does this for every i
	                if (i % j == 0) {
	                	//the code goes in here and it is not PRIME if in here
	                    isPrime = false;
	                    break;
	                }
	            }
	            //if the number was NOT divisible by anything other than itself then it is prime
	            if (isPrime) {
	                System.out.print(" " + i);
	            }
	        }
	    }
	    else if (n == 1){
	    	System.out.print(" 1");
	    }
	    else {
	        System.out.print("Please enter a valid int greater than or equal to 1.");
	    }
	}

}
