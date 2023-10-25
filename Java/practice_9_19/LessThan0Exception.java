package practice_9_19;

public class LessThan0Exception extends Exception{

	/**
	 * 
	 */
	private static final long serialVersionUID = 1L;
	//this was used for the other commented out code but it doesnt harm anything so left it here
	private long num;
	
	public LessThan0Exception() {
		super();
		num = 1;
	}
	public LessThan0Exception(String args) {
		super(args);
		num = 1;
	}
	
	//code for the error handling to happen here

	/*
	public long getFact(long fact) {
		try {
			if (fact < 0) {
				throw new LessThan0Exception("Enter a positive number!");
			}
			else if (fact == 0) {
				throw new LessThan0Exception("Enter a positive INT greater than 0!");
			}
			else {
				for (long i = 1; i <= fact; i++) {
					num = num * (i);
				}
			}
			return num;
		} catch (Exception e) {
			System.out.println(e.getMessage());
			return -1;
		}
	}*/
}
