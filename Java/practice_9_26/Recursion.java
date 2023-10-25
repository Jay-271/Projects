package practice_9_26;
//Jason Avila-Soria Recursion Binary Search

import java.util.*;

public class Recursion {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		ArrayList<Integer> list = new ArrayList<>();
		list.add(3, 3);
		list.add(9, 10);
		
		
		int[] array = new int[10];
		int key = 10;
		array[9] = 10;
		array[3] = 3;
		
		//from previous assignment, just copied it over to help me test my recursive search.
		int position = binarySearch(array, key);
		System.out.println(position);
		
		//needs more parameters for pointers, also needs length and starting pos.
			//also needs to be sorted first before called
		arraySort(array);
		position = recursiveBinary(array, key, 0, array.length);
		System.out.println(position);
		
	}
	
	//returns the position of an element that is the key
	public static int recursiveBinary(int[] array, int key, int low, int high) {
		//set the right mid point
		int mid = (low + high)/2;
		
		//if the key is not in the array return -1
		if (low > high) {
			return -1;
		}
		//base case 1 is comparing if the mid value is the key, if not then return where the key is in the array
		if (key == array[mid]) {
			return mid;
		}
		if (key < array[mid]) {
			return recursiveBinary(array, key, low, mid-1);
		}
		if (key > array[mid]) {
			return recursiveBinary(array, key, mid+1, high);
		}
		
		//if all cases fail retrun -1
		return -1;

	}
	public static int binarySearch(int[] array, int key) {
		//sort first
		arraySort(array);
		
		boolean found = false;
		int low = 0, high = array.length -1;
		
		while (low <= high && !found) {
	        int mid = (low + high) / 2;

	        if (key == array[mid]) {
	            return mid;
	        } else if (key < array[mid]) {
	            high = mid - 1; //key in first half
	        } else {
	            low = mid + 1; //key in second half
	        }
	    }
		
		return -1;
	}
	
	//bubble sort
	public static void arraySort(int[] array) {
		for (int i = 0; i < array.length - 1; i++) { //loop through 0-size of array
														//iterates through WHOLE array
			
		    for (int j = 0; j < array.length - 1 - i; j++) {// this loop goes through each iteration of the array above to make sure in each cycle
		    													//that the correct number is swapped.
		        if (array[j] > array[j + 1]) {
		            int temp = array[j];
		            array[j] = array[j + 1];
		            array[j + 1] = temp;
		        }
		    }
		}
		return;
	}
	
	///do at home
	public static void quickSort(int[] array) {
		int pivot = array[array.length];
		
		for (int i = 0; i < array.length - 1; i++) {
			for (int j = array.length; j > i; j--) {
				if (array[i] < array[j]) {
					int temp = array[i];
					array[i] = array[j];
					array[j] = temp;
				}
			}
		}
	}
	
}
