package practice_9_7_assignment_1;
import java.util.Random;

public class Assign_1 {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//construct new crypto object and init a test sentence and init random generator
		Crypto test = new Crypto();
		String message = "ThiS is a TesT seNtenCE no. 1 [akaZ FIrst_Test} + hello";
		Random rand = new Random();
		//key for the binarysearch
		int key = 6;
		//key for the encoding
		int key2 = 5;
		
		//encode message and print encoded result
		String result = test.Encode(message, key2);
		System.out.println(result);
		
		//decode the message and print result
		message = test.Decode(result, key2);
		System.out.println(message + "\n");

		//initilize and add random numbers to an array size 1-30 with contents 0-10
		int[] array = new int[rand.nextInt(30) + 1];
		for (int count = 0; count < array.length; count++) {
			array[count] = rand.nextInt(11);
			System.out.print(array[count] + " ");
		}
		
		//message to user to say if key was found (-1 if it wasnt)
		System.out.print("\nThe value " + key + " was found in position: " + Crypto.binarySearch(array, key) + " in the array:\n");
		for (int i = 0; i < array.length; i++) {
			System.out.print(array[i] + " ");
		}	
		System.out.print("\n");
		
		//to clearly see where the key(s) were found
		for (int i = 0; i < array.length; i++) {
			if (array[i] == key) {
				System.out.print("^ ");
			}
			else
				System.out.print("  ");
		}	
		
	}

}
