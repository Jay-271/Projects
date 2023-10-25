package Practice_8_29;
import java.util.Random;

public class dinner {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		int num = 0;
		
		Random rand = new Random();
		//generate 1-4
		num = rand.nextInt(4) + 1;
		
		if (num == 1 || num == 2) {
			System.out.println("Pizza ");
		}
		else if (num == 3) {
			System.out.println("Bibimap ");
		}
		else if (num == 4) {
			System.out.println("Couscous ");
		}
	}

}
