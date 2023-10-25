import java.util.Scanner;

public class Random_Num {
	public static void main(String[] args) {
		
		//declare all values and init
		double num = 0, avg = 0, largest = 0, smallest = 0, numCount = 0;
		Scanner In = new Scanner(System.in);
		System.out.println("Please enter your numbers, enter a negative int number to stop.");
		num = In.nextDouble();
		
		//checks if negative value and if not just skip
		if (num >= 0) {
			smallest = num;
		}
		numCount++;
		
		//checks negative value and if it is end the loop
		while (num >= 0) {
			
			//compares current num to largest num
			if (num > largest) {
				largest = num;
			}
			//compares smallest num to current num
			else if (num < smallest) {
				smallest = num;
			}
			//adds all numbers together
			avg += num;
			
			//users next input
			num = In.nextDouble();
			//if the number is valid then increase the counter, if not just calculate the average and then the loop will exit
			if (num >= 0) {
				numCount++;
			}
			else {
				avg = avg/numCount;
			}
		}
		
		//display final message
		System.out.println("The highest num was: " + largest + "\nThe Smallest Num was: " + smallest + "\nThe Average was: " + avg);
			In.close();
	}
}

