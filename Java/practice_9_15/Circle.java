package practice_9_15;

public class Circle implements Shapes{
	private double area, perim, rad;

	Circle() {
		area = 0;
		perim = 0;
		rad = 0;
	}
	Circle(double rad) {
		this.rad = rad;
		area = 0;
		rad = 0;
	}
	
	@Override
	public double getArea() {
		// TODO Auto-generated method stub
		area = Math.PI * rad * rad;
		
		return area;
	}

	@Override
	public double getPerimeter() {
		// TODO Auto-generated method stub
		perim = Math.PI * 2 * rad;
		return perim;
	}

}
