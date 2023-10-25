package practice_10_12;

public class TestGenStack {
	public static void main(String[] args) {
		GenericStack<Integer> intstack = new GenericStack<>();
		GenericStack<String> stringstack = new GenericStack<>();
		GenericStack<Character> charstack = new GenericStack<>();
		
		Stack javastack = new Stack();
		
		String openBrack = "{";
		String closeBrack = "}";
		String openPer = "(";
		String closePer = ")";
		String openSq = "[";
		String closedSq = "]";
		//////finish deli thing to with own stack and library stack
		
		
		intstack.push(123);
		intstack.display();
		stringstack.push("Bozo");
		stringstack.display();
	}
}
