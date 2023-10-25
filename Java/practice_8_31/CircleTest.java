package practice_8_31;

public class CircleTest {

	public static void main(String[] args) {
		Circle cir1 = new Circle();
		double area = 0;
		String color = "";
		
		cir1.setColor("Red");
		cir1.setRadius(10);
		
		area = cir1.getArea();
		color = cir1.getColor();
		
		System.out.println("The area for the " + color + " circle was: "+ area);
		Circle cir2 = new Circle();
		double area2 = 0;
		String color2 = "";

		cir2.setColor("Blue");
		cir2.setRadius(20);
		
		area2 = cir2.getArea();
		color2 = cir2.getColor();
		
		System.out.println("The area for the " + color2 + " circle was: "+ area2);
	}

}
