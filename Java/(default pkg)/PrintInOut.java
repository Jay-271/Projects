import java.util.Scanner;

public class PrintInOut {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		System.out.println("Please enter two integers: ");
		
		int a, b;
		
		Scanner myInput = new Scanner(System.in);
		
		a = myInput.nextInt();
		b = myInput.nextInt();
		
		
		System.out.println("The sum of the two numbers is: " + (a + b));
	
		System.out.println("Please enter two Floats: ");
		float c, d;
		
		c = myInput.nextFloat();
		d = myInput.nextFloat();
		
		System.out.println("The sum of the two float Numbers are: " + (c + d) + "\nPlease enter your word: ");
		
		String e, f;
		//to capture previous \n
		e = myInput.nextLine();
		
		e = myInput.next();

		System.out.println("Your Word was: " + e + "\nPlease enter your next word: ");
		
		f = myInput.next();
		
		System.out.println("Your word was: " + f + "\nPlease enter your sentence: ");
		
		e = myInput.nextLine();
		
		System.out.println("Youre sentence was: " + e + "\nPlease enter your next sentence: ");
		
		f = myInput.nextLine();
		
		System.out.println("Your sentence was: " + f);
		
		myInput.close();
	}

}
