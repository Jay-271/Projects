package practice_9_1;

public class Student {
	
	private int id = 0;
	private String name = "";
	private double midTermGrade = 0, finalExamGrade = 0, gpa = 0;
	
	public Student(int ID, String NAME, double midTerm, double finalExam) { 
		midTermGrade = midTerm;
		finalExamGrade = finalExam;
		name = NAME;
		id = ID;
	}
	
	public int getID() {
		return id;
	}
	public String getName() {
		return name;
	}
	public double getMidGrade() {
		return midTermGrade;
	}
	public double getFinalGrade() {
		return finalExamGrade;
	}
	public String getGPA() {
		gpa = (finalExamGrade + midTermGrade) / 2;
		
		if (gpa <= 100 && gpa >= 90) {
			return "A (" + gpa + ")";
		}
		else if (gpa < 90 && gpa >= 80) {
			return "B (" + gpa + ")";
		}
		else if (gpa < 80 && gpa >= 70) {
			return "C (" + gpa + ")";
		}
		else if (gpa < 70 && gpa >= 60) {
			return "D (" + gpa + ")";
		}
		else {
			return "F (" + gpa + ")";
		}
	}
}
