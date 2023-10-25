package Practice_10_5_Assignment_2;

import java.io.*;
import java.util.*;

public class TestShapes {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		//make shapes array size of total shapes given in files
		Shapes[] arrOfShapes = new Shapes[11];
		//init files
		File circle = new File("circle.txt");
		File rect = new File("rectangle.txt");
		File tria = new File("triangle.txt");
		
		Scanner in = null;
		
		try { //read circle
			in = new Scanner (circle);
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			System.out.println(e);
		}
		
		//counter to continue outside the loop for the rest of the shapes in shapes array
		int counter = 0;		
		for (int i = 0; in.hasNextLine(); i++) {
			arrOfShapes[i] = new Circle((in.nextDouble()));
			counter++;
		}

		in.close();
		
		try {//read rectangle
			in = new Scanner(rect);
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			System.out.println(e);
		}
		
		for (int i = counter; in.hasNextLine(); i++) {
			arrOfShapes[i] = new Rectangle((in.nextInt()), (in.nextDouble()));
			counter++;;
		}
		in.close();
		
		try { // read triangle
			in = new Scanner(tria);
		} catch (FileNotFoundException e) {
			// TODO Auto-generated catch block
			System.out.println(e);
		}

		for (int i = counter; in.hasNextLine(); i++) {
			arrOfShapes[i] = new Triangle(in.nextDouble(), in.nextDouble(), in.nextDouble());
			counter++;
		}
		
		
		//calculate final area and final perim
		System.out.print("Areas for the Rectangle, circle, and triangle respectively: ");
		double finalArea = 0;
		for (int j = 0; j < arrOfShapes.length; j++) {
			finalArea += arrOfShapes[j].getArea();
		}
		System.out.println(finalArea);
		
		double finalPerim = 0;
		System.out.print("\nPerimiter for the Rectangle, circle, and triangle respectively: ");
		for (int j = 0; j < arrOfShapes.length; j++) {
			finalPerim += arrOfShapes[j].getPerimeter();
		}
		System.out.println(finalPerim);

		in.close();
		System.exit(0);
	}

}
