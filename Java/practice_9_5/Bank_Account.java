package practice_9_5;
/**
 * This class makes new bank accounts
 * The methods return the information from a bank account.
 * 
 * @author Jason Avila-Soria
 */
public class Bank_Account {
	private int accID;
	private String username;
	private double balance;
	public static final double INTEREST_RATE = .065;
	public static int totalAccounts = 0;
	
	/**
	 * 
	 * @param ID is the unique ID for every bank account
	 * @param name is the name of the user
	 */
	Bank_Account(int ID, String name) {
		this.accID = ID;
		this.username = name;
		balance = 0;
		totalAccounts++;
	}
	
	/**
	 * 
	 * @return returns the unique ID of a user
	 */
	public int getID() {
		return accID;
	}
	/**
	 * 
	 * @return returns the username of the user
	 */
	public String getName() {
		return username;
	}
	/**
	 * 
	 * @param amount is the amount to take away from the account
	 * @return returns the new balance after withdrawal
	 */
	public double withdraw(double amount) {
		this.balance -= amount;
		return balance;
	}
	/**
	 * 
	 * @param amount is the new amount to add to the balance
	 * @return returns the new balance
	 */
	public double deposit(double amount) {
		this.balance += amount;
		return balance;
	}
	/**
	 * 
	 * @return returns the current balance
	 */
	public double checkBalance() {
		return balance;
	}
	/**
	 * 
	 * @return returns the current interest rate
	 */
	public double checkRate() {
		return Bank_Account.INTEREST_RATE;
	}
 }
