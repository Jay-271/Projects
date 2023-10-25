package Practice_10_5_Assignment_2;

public class Rectangle implements Shapes {
	private double length, width, area, perim;
	
	Rectangle() {
		length = 0;
		width = 0;
		area = 0;
		perim = 0;
	}
	Rectangle(double length, double width) {
		this.length = length;
		this.width = width;
		area = 0;
		perim = 0;
	}

	@Override
	public double getArea() {
		// TODO Auto-generated method stub
		area = length * width;
		return area;
	}

	@Override
	public double getPerimeter() {
		// TODO Auto-generated method stub
		perim = 2 * (length + width);
		return perim;
	}
}
