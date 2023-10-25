package practice_9_15;

public class TestShapes {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Shapes[] arrOfShapes = new Shapes[3];
		arrOfShapes[0] = new Rectangle(2, 2);
		arrOfShapes[1] = new Circle(10);
		arrOfShapes[2] = new Triangle(3, 3, 3);
		
		System.out.println("Areas for the Rectangle, circle, and triangle respectively:");
		for (int i = 0; i < arrOfShapes.length; i++) {
			System.out.print(arrOfShapes[i].getArea() + " | ");
		}
		System.out.println("\n\nPerimiter for the Rectangle, circle, and triangle respectively:");
		for (int i = 0; i < arrOfShapes.length; i++) {
			System.out.print(arrOfShapes[i].getPerimeter() + " | ");
		}
	}

}
