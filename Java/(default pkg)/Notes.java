//read in and out
//import java.util.Scanner;
//random class
import java.util.Random;

public class Notes {
	
	//called  method to do for a specific piece of code.
	public static void main(String[] args) {

		System.out.println("Hello Java!");
		int num = 0;
		//to get [0-100)
		num = (int)(Math.random()*101);
		//10-110
		num = (int)(Math.random()*101 + 10);
		
		//using the random class:
		
		Random rand = new Random();
		//the NEW ccalls the constructors to make a *** object
		
		//some methods like nextint generate nums between a lot of negative and positive
			//if value in () then gives between [0 and num)
				//below give 0-10
		num = rand.nextInt(11);
		
		// STATIC VS INSTANCE VARIABLES!!!! <><><><><><><><><><><><><><><><><><>
		/*declaring an instance variable (String color = red) in a class, each car can have their own color
		 * having a static one changes it FOR ALL OBJECTS (Static int Wheels = 4) 
		 * 
		 * --> "this" keyword refers to "this" object name (nearest object)
		 * 		-> cir1.radius = r => this.radius = r
		 * 			-> ONLY used for instance variables (each object (when created) has their own set like String color;)
		 * 
		 * to change static variables since it shared use the class name so "Circle.color = "green";
		 * 
		 */
		
		
	}

}

