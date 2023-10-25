package practice_9_12;

public class Person {
	private String name;
	private String BannerID;
		
	public Person() {
		name = "";
		BannerID = "";
	}
	public Person(String name, String BannerID) {
		this.name = name;
		this.BannerID = BannerID;
	}
	public void setName(String newName) {
		name = newName;
	}
	public String getName() {
		return name;
	}
	public String getBannerID() {
		return BannerID;
	}
	public void writeOutput() {
		System.out.println("Name: " + name + "\nBannerID: " + BannerID);
	}
}
