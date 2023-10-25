package practice_10_12;

public class Stack{	
	private  int[] data;
	private  int capacity;
	private  int count;
	
	public Stack() {
		capacity = 5;
		count  = 0;
		data = new int[capacity];
	}
	
	public void push(int psh) {
		if (count >= capacity) {
			int[] newArr = new int[capacity * 2];
			for (int i = 0; i < count; i++) {
				newArr[i] = data[i];
			}
			data = newArr;
			capacity *= 2;
		}
		data[count] = psh;
		count++;
		
	}
	
	public  int pop() throws Exception {
		if (count == 0) {
			throw new Exception("The stack is empty!");
		}
		count--;
		return data[count];
	}
	
	public  int peek() throws Exception {
		if (count == 0) {
			throw new Exception("The stack is empty!");
		}
		return data[count];
	}
	
	public  boolean isEmpty() {
		if (count == 0) {
			return true;
		}
		
		return false;
	}
	
	public  void clear() {
		count = 0;
	}
	public void display() {
		for (int i = 0; i < count; i++) {
			System.out.print(data[i] + " ");
		}
	}
	
}
