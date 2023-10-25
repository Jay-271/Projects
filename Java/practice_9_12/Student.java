package practice_9_12;

public class Student extends Person {
	private String major;
	private double GPA;
	
	public Student() {
		super();
		major = "";
		GPA = 0;
	}
	public Student (String name, String BannerID, String major, double GPA) {
		super(name, BannerID);
		this.major = major;
		this.GPA = GPA;
	}
	public String getName() {
		return "Student: " + super.getName();
	}
	public String getBannerID() {
		return "BannerID: " + super.getBannerID();
	}
	
	public void resetName(String newName) {
		super.setName(newName);
	}
	public String getMajor() {
		return major;
	}
	public void setMajor(String major) {
		this.major = major;
	}
	public double getGPA() {
		return GPA;
	}
	public void setGPA(double GPA) {
		this.GPA = GPA;
	}
	public void writeOutput() {
		super.writeOutput();
		System.out.println("\nMajor: " + major + "\nGPA: " + GPA);
	}
}
