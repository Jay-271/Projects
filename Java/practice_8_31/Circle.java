package practice_8_31;

public class Circle {
	private double radius, area;
	private String color;
		
	public Circle () { //this is the consctructor
		radius = 0;
		area = 0;
		color = "";
	}
	
	public void setRadius(double num) {
		radius = num;
	}
	
	public void setColor(String c) {
		color = c;
	}

	public double getArea() {
		area = (radius * radius) * 3.14;
		return area;
	}
	public String getColor() {
		return color;
	}
	
}