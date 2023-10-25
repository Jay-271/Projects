package practice_9_5;

public class Bank {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		//two test accs initlized
		Bank_Account acc1 = new Bank_Account(1, "Jason");
		Bank_Account acc2 = new Bank_Account(2, "Ricardo");

		acc1.deposit(1000);
		acc2.deposit(1500);
		
		//get average interest rate to double money
		int years1 = 0;
		while (acc1.checkBalance() < 2000) {
			acc1.deposit(acc1.checkBalance() * acc1.checkRate());
			years1++;
		}
		int years2 = 0;
		while (acc2.checkBalance() < 3000) {
			acc2.deposit(acc2.checkBalance() * acc2.checkRate());
			years2++;
		}
		
		System.out.println("It took ID: " + acc1.getID() + " (" + acc1.getName() + ") " + years1 + " years to double their money from 1000 dollars, now about " + (int)acc1.checkBalance() + " dollars.");
		System.out.println("It took ID: " + acc2.getID() + " (" + acc2.getName() + ") " + years2 + " years to double their money from 1000 dollars, now about " + (int)acc2.checkBalance() + " dollars.");
		System.out.println("The interest rate was: " + Bank_Account.INTEREST_RATE * 100 + "%");
		
		//initilize array of 5 Bank Account pointers
		Bank_Account[] multiAccs = new Bank_Account[5];
		//send it to the function to put some money in there 100-1000 and name each account
		initilize_Test_accs(multiAccs);			
		double average = 0;
		
		//calculate average and display each person's balance
		for (int i = 0; i < multiAccs.length; i++) {
			average += multiAccs[i].checkBalance();
			System.out.print(multiAccs[i].getName() + "'s balance: " + multiAccs[i].checkBalance() + "\n");
			
			if (i == multiAccs.length-1) {
				average = average / multiAccs.length;
				System.out.println("The average balance was: " + average);
			}
		}
		
	}
	//method to initilize names and starting money
	public static void initilize_Test_accs (Bank_Account[] multiAccs) {
		for (int i = 0; i < multiAccs.length; i++) {
			int j = 2;
			String name = new String("testName_no." + (i+1));
			
			multiAccs[i] = new Bank_Account(j, name);
			j++;
			multiAccs[i].deposit((int)(Math.random()*901  + 100));
		}
	}

}
