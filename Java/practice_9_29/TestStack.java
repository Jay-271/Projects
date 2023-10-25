package practice_9_29;

public class TestStack {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		Stack list = new Stack();
		int size = (int)(Math.random()* 100 + 1);
		for (int i = 0; i < size; i++) {
			list.push((int)(Math.random()* 100 + 1));
		}

		list.display();
		list.sort();
		System.out.println();
		list.display();
		
		
		while(!list.isEmpty()) {
			System.out.println("\n");
			try {
				list.pop();
			}catch(Exception e) {
				System.out.println("Error: " + e);
				System.exit(-1);
			}
			finally {
				list.display();
			}
		}
		
		
	}

}
