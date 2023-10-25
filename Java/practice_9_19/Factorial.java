package practice_9_19;

import java.util.Scanner;

public class Factorial {
	public static void main(String[] args) {
		
		Scanner in = new Scanner(System.in);
		long fact = 0;
		long num = 1;
		int chancesToTryInput = 0;
		
		System.out.print("Please enter a number to get the factorial for it: ");
		//LessThan0Exception e = new LessThan0Exception();
		
		//code for user to keep trying until value above one is reached
		do {
			fact = in.nextInt();
			
			try {
				if (fact < 0) {
					throw new LessThan0Exception("Enter a positive number!");
				}
				else if (fact == 0) {
					throw new LessThan0Exception("Enter a positive INT greater than 0!");
				}
				else {
					for (long i = 1; i <= fact; i++) {
						num = num * (i);
					}
				}
			} catch (LessThan0Exception e) {
				System.out.println(e.getMessage());
				num = -1;
				chancesToTryInput++;
			}
			
			//num = e.getFact(fact);
		}while (num < 0 && chancesToTryInput != 2);
		
		//error handling + chances, can remove chances for unlimited attempts
		if (chancesToTryInput == 2) {
			System.out.println("Too many chances. Now exiting.");
			in.close();
			System.exit(0);
		}
		else {
			System.out.println(num);
			in.close();
			System.exit(0);
		}
		
	}
}
