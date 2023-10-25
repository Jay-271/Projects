package practice_9_12;

public class Employee extends Person{
	double salary;
	String dept;
	String title;
	
	Employee() {
		super();
		salary = 0;
		dept = "";
		title = "";
	}
	Employee(String name, String BannerID, String dept, double salary) {
		super(name, BannerID);
		this.salary = salary;
		this.dept = dept;
		title = "Employee";
	}
	
	public String getName() {
		return "Employee: " + super.getName();
	}
	public String getBannerID() {
		return "BannerID: " + super.getBannerID();
	}
	public String getDepartment() {
		return dept;
	}
	public String getTitle() {
		return title;
	}
	public void setTitle(String title) {
		this.title = title;
	}
	public void writeOutput() {
		super.writeOutput();
		System.out.println("Title: "+ this.getTitle() + "\nDepartment: " + this.getDepartment());
	}
}
