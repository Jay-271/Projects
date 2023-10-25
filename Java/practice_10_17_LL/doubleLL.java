package practice_10_17_LL;

//with dummy head & tail
public class doubleLL {
    private Node head;
    private Node tail;
	private int counter;

    public class Node {
		private int data;
		Node next;
        Node prev;
	}

    public doubleLL() {
        head = new Node();
        tail = new Node();
        head.next = tail;
        tail.prev = head;
        tail.next = null;
        head.prev = null;
        counter = 0;
    }

    public void remove(int a) throws Exception {
        Node curr = head.next;

        while (curr != tail) {
            if (curr.data == a) {
                curr.prev.next = curr.next;
                curr.next.prev = curr.prev;
                counter--;
                return;
            }
            curr = curr.next;
        }
        throw new Exception("Value " + a + " not found.");

    }
    public void insertAfter(int a, int b) throws Exception {
        //insert a after b
        Node add = new Node();
        Node curr = head.next;

        add.data = a;
        while (curr.next != tail) {
            if (curr.data == b) {
                curr.next.prev = add;
                add.next = curr.next;
                curr.next = add;
                add.prev = curr;
                counter++;
                return;
            }
            curr = curr.next;
        }
        throw new Exception(b + " doesnt exist!");

    }
    public void append(int a) {
		//adds node to end
		Node temptail = tail;
		Node nwNode = new Node();
		nwNode.data = a;

        temptail = temptail.prev;

        temptail.next = nwNode;
        nwNode.next = tail;
        tail.prev = nwNode;

		counter++;
		return;
	}
    public void preprend(int a) {
        Node temphead = head;
        Node nwNode = new Node();
        nwNode.data = a;

        temphead = temphead.next;
        
        temphead.prev = nwNode;
        nwNode.next = temphead;
        head.next = nwNode;
        counter++;
        return;
    }
    public void display() {
		Node temp = head.next;
		System.out.println("The LL has the following values:");
		while(temp != tail) {
			System.out.print(temp.data + " ");
			temp = temp.next;
		}
	}
    public boolean contains(int a) {
        Node temp = head.next;
        while(temp != tail) {
            if (temp.data == a) {
                return true;
            }
            temp = temp.next;
        }
        
        return false;
    }
    public boolean isEmpty() {
		if (counter == 0) {
           return true;
        }
        return false;
	}
    public void clear() {
		head.next = tail;
        tail.prev = head;
        tail.next = null;
        head.prev = null;
        counter = 0;
	}
    public void merge(doubleLL linked1, doubleLL linked2) {
        Node l1 = linked1.tail.prev;

        Node curr1 = linked1.head.next;
        Node curr2 = linked2.head.next;

        while (curr1.next != linked1.tail && curr2.next != linked2.tail) {
            if (curr1.data == curr2.data) {
                try {
                    linked2.remove(curr2.data);
                } catch (Exception e) {
                    System.out.println("Couldn't remove " + curr2.data + ". Error: " + e);
                }
            }
            curr1 = curr1.next;
            curr2 = curr2.next;
        }
        
        if (!linked2.isEmpty()) {
            l1.next = linked2.head.next;
            linked2.head.next.prev = l1;

           linked2.head = null;
        }


    }
    public static void main(String[] args) {
        doubleLL nLL = new doubleLL();
        nLL.append(200);
        nLL.preprend(199);
        nLL.preprend(148);
        nLL.append(12);
        int value = 199;
        boolean has = nLL.contains(value);
        nLL.display();
        if (has) {
            System.out.println("\nfound " + value);
        }

    }

}
