package practice_10_12;

public class GenericStack<T> {
	private int count;
	private int capacity;
	private T[] data;
	
	public GenericStack() {
		count  = 0;
		capacity = 100;
		data = (T[])new Object[capacity];
	}
	
	public void push(T psh) {
		if (count >= capacity) {
			T[] newArr = (T[])new Object[capacity * 2];
			
			for (int i = 0; i < count; i++) {
				newArr[i] = data[i];
			}
			data = newArr;
			capacity *= 2;
		}
		data[count] = psh;
		count++;
	}
	
	public T pop() throws Exception {
		if (count == 0) {
			throw new Exception("The stack is empty!");
		}
		count--;
		return data[count];
	}
	
	public T peek() throws Exception {
		if (count == 0) {
			throw new Exception("The stack is empty!");
		}
		return data[count];
	}
	
	public boolean isEmpty() {
		if (count == 0) {
			return true;
		}
		return false;
	}
	
	public void clear() {
		count = 0;
	}
	public void display() {
		for (int i = 0; i < count; i++) {
			System.out.print(data[i] + " ");
		}
	}
	public int capacityUsed() {
		return count;
	}
	
	
}
