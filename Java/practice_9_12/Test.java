package practice_9_12;

public class Test {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		
		Student stu1 = new Student("Jason", "A001", "CSCI", 3.9);
		System.out.println(stu1.getName() + "\n" + stu1.getBannerID() + "\nMajor: " + stu1.getMajor() + "\n");
		
		Student stu2 = new Student("Jake", "A002", "JAPN", 4.01);
		System.out.println(stu2.getName() + "\n" + stu2.getBannerID() + "\nMajor: " + stu2.getMajor() + "\n");
		
		Person[] committee = new Employee[4];
		
		
		for (int i = 0; i < committee.length; i++) {
			committee[i] = new Employee("Robert No. " + (i+1), "B00" + (i+1), "Software Engineer", + 9000);
			committee[i].writeOutput();
			System.out.println();
		}		
	}
}
