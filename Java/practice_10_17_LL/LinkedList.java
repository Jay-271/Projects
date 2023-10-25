package practice_10_17_LL;

public class LinkedList {
	
	public class Node {
		private int data;
		private Node next;
	}

	private Node head;
	private int counter;

	public LinkedList() {
		head = new Node();
		head.next = null;
		counter = 0;
	}

	public void append(int a) {
		//adds node to end
		Node temp = head;
		Node nwNode = new Node();
		
		nwNode.data = a;
		nwNode.next = null;
		
		while(temp.next != null) {
			temp = temp.next;
		}

		temp.next = nwNode;
		counter++;
		return;
	}
	public void prepend(int a) {
		Node nwNode = new Node();

		nwNode.next = head.next;
		head.next = nwNode;
		nwNode.data = a;
		counter ++;
		return;
	}
	public void remove(int a) throws Exception {
		//throw if a doesnt exist
		Node current = head;
		Node prevNode = head;
		while (current.next != null) {
			//edge case 1st
			
			if (current.next.data == a && counter == 0) {
				head.next = null;
			}
			else if (current.data == a){
				prevNode.next = current.next;
				counter--;
				return;
			}
			//edge case end
			else if (current.next.next == null && current.next.data == a) {
				current.next = null;
				counter--;
				return;
			}
			current = current.next;
			prevNode = prevNode.next;
		}

		throw new Exception(a + " Doesn't exist!");
	}
	//a = num to add, b = num to add BEFORE NODE VALUE b
	public void insertBefore(int a, int b) throws Exception {
		Node current = head.next;
		Node prevNode = head;
		Node nwNode = new Node();
		
		nwNode.data = a;
		while (current.next != null) {
			//edge case 1st
			
			if (current.next.data == b && counter == 0) {
				head.next = nwNode;
			}
			else if (current.data == b){
				nwNode.next = prevNode.next;
				prevNode.next = nwNode;
				
				counter++;
				return;
			}
			//edge case end
			else if (current.next.next == null && current.next.data == b) {
				current.next = nwNode;
				return;
			}
			current = current.next;
			prevNode = prevNode.next;
		}

		//throws exception if b doesnt exist
		throw new Exception(b + "Doesn't exist!");
	}
	
	//a = num to add, b = num to add AFTER NODE VALUE B
	public void insertAfter(int a, int b) throws Exception {
		Node current = head.next;
		Node nwNode = new Node();
		
		nwNode.data = a;
		while (current.next != null) {
			//edge case 1st
			if (current.next.data == b && counter == 0) {
				head.next = nwNode;
			}
			else if (current.data == b){
				nwNode.next = current.next;
				current.next = nwNode;

				counter++;
				return;
			}
			//edge case end
			else if (current.next.next == null && current.next.data == b) {
				current.next = nwNode;
				return;
			}
			current = current.next;
		}

		//throws exception if b doesnt exist
		throw new Exception(b + "Doesn't exist!");
	}
	public boolean contains(int a) throws Exception {
		Node current = head;

		while (current.next != null) {
			//edge case 1st
			if (current.next.data == a && counter == 0) {
				return true;
			}
			else if (current.data == a){
				return true;
			}
			//edge case end
			else if (current.next.next == null && current.next.data == a) {
				return true;
			}
			current = current.next;
		}
		throw new Exception(a + " is not here!");
	}
	public int getLength() {
		
		return counter;
	}
	public void clear() {
		head.next = null;
		counter = 0;
		return;
	}
	public boolean isEmpty() {
		if (counter == 0) {
			return true;
		}
		return false;
	}
	public void display() {
		Node temp = head.next;
		System.out.println("The LL has the following values:");

		if (counter == 0 && temp.next == null) {
				System.out.print(temp.data + " ");
			}
		else {
			while(temp != null) {
			System.out.print(temp.data + " ");
			temp = temp.next;
			}
		}
		
	}

	public static void main(String[] args) {
		LinkedList LL = new LinkedList();
		//apend one item
		LL.append(12);
		LL.display();
		System.out.println();

		//remove that item
		try {
		LL.remove(12);
		}catch(Exception e) {
			System.out.println(e);
		}
		
		//try appending more
		LL.append(10);
		LL.append(34);
		LL.prepend(999);
		LL.prepend(21);
		LL.display();
		System.out.println();

		//try insert before
		try {
			LL.remove(34);
		} catch (Exception e) {
			System.out.println(e);
		}
		LL.display();
		System.out.println();

		try {
			LL.insertBefore(177, 999);
		} catch (Exception e) {
			System.out.println(e);
		}
		LL.display();
		System.out.println();

		//try insert after
		try {
			LL.insertAfter(555, 999);
		} catch (Exception e) {
			System.out.println(e);
		}
		LL.display();
		System.out.println();

		int thing_to_check = 21;
		try {
			if(LL.contains(thing_to_check)) {
				System.out.println("LL contains " + thing_to_check);
			}
		} catch (Exception e) {
			System.out.println(e);
		}

	}
}
