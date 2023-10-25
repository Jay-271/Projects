package practice_10_12;
import java.util.Stack;
import java.util.*;

public class CheckDelimiter {
	public static void main(String[] args) {
		boolean balanced = true;
		boolean javabalanced = true;
		GenericStack<Character> st = new GenericStack<>();
		//javastack
		Stack<Character> javast = new Stack<>();
		Scanner in = new Scanner(System.in);
		
		//type expression in 
        System.out.print("Enter your expression: ");
		String test = in.nextLine();
		char[] chtest = test.toCharArray();
		
		//send it to the stack or check stack
		for (char x : chtest) {

            if (balanced) {
                switch (x) {
                    case '{':
                    case '(':
                    case '<':
                    case '[':
                        st.push(x);
                        javast.push(x);
                        break;
                    case '}':
                    case ')':
                    case ']':
                    case '>':
                        balanced = checkpop(x, st);
                        javabalanced = javacheckpop(x, javast);
                        break;
                }
            } else {
                break;
            }
        }
		
		//final message if balanced or not.
        System.out.println();
        if (balanced && st.isEmpty()) {
            System.out.println("The expression is balanced.");
        } else {
            System.out.println("The expression is not balanced.");
        }
        
        System.out.println();
        if (javabalanced && javast.isEmpty()) {
            System.out.println("The expression is balanced (javastack).");
        } else {
            System.out.println("The expression is not balanced (javastack).");
        }
	
	}
	
	private static boolean checkpop(char x, GenericStack<Character> st) {
		char popped = '.';
		
		if (st.isEmpty()) {
            System.out.println("No open bracket left in the stack!");
            return false;
        }

        try {
			popped = st.pop();
		} catch (Exception e) {
            System.out.println("Mismatched brackets!");
		}

        if (x == '}' && popped == '{') {
            return true;
        } else if (x == ')' && popped == '(') {
            return true;
        } else if (x == ']' && popped == '[') {
            return true;
        } else if (x == '>' && popped == '<') {
        	return true;
        } else {
            System.out.println("Mismatched brackets!");
            return false;
        }
		
	}
	private static boolean javacheckpop(char x, Stack<Character> st) {
		char popped = '.';
		
		if (st.isEmpty()) {
            System.out.println("No open bracket left in the stack (javastack)!");
            return false;
        }

        try {
			popped = st.pop();
		} catch (Exception e) {
            System.out.println("Mismatched brackets (javastack)!");
		}

        if (x == '}' && popped == '{') {
            return true;
        } else if (x == ')' && popped == '(') {
            return true;
        } else if (x == ']' && popped == '[') {
            return true;
        } else if (x == '>' && popped == '<') {
        	return true;
        } else {
            System.out.println("Mismatched brackets!");
            return false;
        }
		
	}
}
