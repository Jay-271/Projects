package Practice_8_29;
//import java.util.Scanner;
import java.util.Random;

public class numbers {

	public static void main(String[] args) {
		int num = 0, largest = 0, smallest = 0, sum = 0, count =0;
		double average;
		
		//Scanner input = new Scanner(System.in);
		Random rand = new Random();

		System.out.println("Enter numbers, ended by a negative: ");
		//num = input.nextInt();
		num = rand.nextInt(100) + 1;
		System.out.print("The numbers are: " + num);
		
		while (num >= 0) {
			if (count == 0) {
				largest = num;
				smallest = num;
			}
			else {
				if (num > largest) {
					largest = num;
				}
				if (num < smallest) {
					smallest = num;
				}
			}
			sum += num;
			count += 1;
			//num = input.nextInt();
			num = rand.nextInt(100) + 1;
			System.out.print(" " + num);
			if (count == 9) {
				num = -1;
				System.out.print(" " + num);
			}
		}
		average = (double)sum/count;
		System.out.println("\nThe average is " + average + "\nThe smallest is: " + smallest + "\nThe largest was: " + largest);
	}

}
