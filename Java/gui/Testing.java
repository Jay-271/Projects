package gui;

import java.util.NoSuchElementException;
import java.util.Scanner;

public class Testing {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Scanner in = new Scanner(System.in);
		
		String something = "";
		
		while (!something.equals("-1")) {
			System.out.println("Choice: \n");
			////trying to avoid the error
			try {
				something = in.nextLine();

			}catch(NoSuchElementException e) {
				System.out.print(e.getMessage());
			}
			////
			
			if (something.equals("1")) {
				something = in.nextLine();
				add1(something);
			}
			else if (something.equals("2")) {
				add1();
			}
		}
	}
	
	public static void add1(String num) {
		int num1 = Integer.parseInt(num);
		
		System.out.println(num1 + 1 + "\n");
	}
	public static void add1() {
		Scanner in = new Scanner(System.in);
		
		int num1 = in.nextInt();
		
		System.out.println(num1 + 1 + "\n");
		in.close();
	}

}
