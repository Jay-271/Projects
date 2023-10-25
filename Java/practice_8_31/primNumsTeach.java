package practice_8_31;

public class primNumsTeach {

	public static void main(String[] args) {
		// TODO Auto-generated method stub

	}
	
	public static void printPrime(int n) {
		int j = 2;
		
		for (int i = 2; i <=n; i++) {		
			
			for (j++; j < i/2; i++) {//idk why compiler saying j++
				
				if (i % j == 0) {
					break;
				}
			}
			if (j == i) {//is a prime
				System.out.print(i + " ");
			}
			j = 2;
		}
	}
}
