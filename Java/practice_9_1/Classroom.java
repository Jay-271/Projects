package practice_9_1;

public class Classroom {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Student stu1 = new Student(1, "Jason", 90, 100);
		int id = stu1.getID();
		String name = stu1.getName();
		double mid = stu1.getMidGrade();
		double finalGrade = stu1.getFinalGrade();
		String gpa  = stu1.getGPA();
		
		System.out.println("ID: " + id + "\nName: " + name + "\nMidTerm Grade: " + mid + "\nFinal Grade: " + finalGrade + 
		"\nThe GPA letter grade was: " + gpa); 

		Student stu2 = new Student(2, "Eli", 50, 92);
		id = stu2.getID();
		name = stu2.getName();
		mid = stu2.getMidGrade();
		finalGrade = stu2.getFinalGrade();
		gpa = stu2.getGPA();
		
		System.out.println("\nID: " + id + "\nName: " + name + "\nMidTerm Grade: " + mid + "\nFinal Grade: " + finalGrade + 
				"\nThe GPA letter grade was: " + gpa); 
	}

}
