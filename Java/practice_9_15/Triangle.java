package practice_9_15;

public class Triangle implements Shapes{
private double length, width, area, perim, height;
	
	Triangle() {
		length = 0;
		width = 0;
		area = 0;
		perim = 0;
		height = 0;
	}
	Triangle(double length, double width, double height) {
		this.length = length;
		this.width = width;
		this.height = height;
		area = 0;
		perim = 0;
	}

	@Override
	public double getArea() {
		// TODO Auto-generated method stub
		double s = (length + width + height)/2;
		
		area = Math.sqrt((s * (s - length) * (s - width) * (s - height)));
		return area;
	}

	@Override
	public double getPerimeter() {
		// TODO Auto-generated method stub
		perim = (length + width + height);
		return perim;
	}
}