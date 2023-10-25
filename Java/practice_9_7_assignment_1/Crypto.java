package practice_9_7_assignment_1;

/**
 * This class contains methods for array sorting, binary searching, and encoding/decoding a string.
 * @author Jason Avila-Soria
 */
public class Crypto {
	
	//private char a = 97, A = 65;
	//private char z = 122, Z = 90;
	//25 letters apart && just noted above to note the ASCII values of a-z, A-Z incase needed.
	
	/**
	 * @param original - original string to encode
	 * @param key - how much to encode a certain letter by, ex: 'a' + 1 = 'b'
	 * @return the encoded string.
	 */
	public String Encode(String original, int key) {
		char[] originalText = original.toCharArray();
		char[] encodedText = new char[original.length()];

		
		for (int i = 0; i < original.length(); i++) {
			char letter;
			letter = originalText[i];			
			if (originalText[i] >= 'a' && originalText[i] <= 'z') {
				
				letter += key;

				if (letter < 'a' || letter >= 'z') {
					//for encoding to the clockwise					
					letter = (char) (letter - 'z' + 'a');
					encodedText[i] = letter;
				}
				else {
					encodedText[i] = letter;
				}				
			}
			else if (originalText[i] >= 'A' && originalText[i] <= 'Z') {
				letter += key;
				
				if (letter < 'A' || letter > 'Z') {
					//for encoding to the clockwise
					letter = (char) (letter - 'Z' + 'A' - 1);
					encodedText[i] = letter;
				}
				else {
					encodedText[i] = letter;
				}
			}
			else {
				encodedText[i] = originalText[i];
			}
			
		}
		//to conver char[] array to a string
		String finalEncode = new String(encodedText);
		
		return finalEncode;
	}
	
	/**
	 * @param original - original string to decode
	 * @param key - how much to decode a certain letter by, ex: 'z' - 1 = 'y'
	 * @return the decoded string.
	 */
	public String Decode(String original, int key) {
		char[] originalText = original.toCharArray();
		char[] encodedText = new char[original.length()];

		
		for (int i = 0; i < original.length(); i++) {
			char letter;
			letter = originalText[i];			
			if (originalText[i] >= 'a' && originalText[i] <= 'z') {
				
				letter -= key;

				if (letter < 'a' || letter >= 'z') {
					//for encoding to the clockwise					
					letter = (char) (letter + 'z' - 'a');
					encodedText[i] = letter;
				}
				else {
					encodedText[i] = letter;
				}				
			}
			else if (originalText[i] >= 'A' && originalText[i] <= 'Z') {
				letter -= key;
				
				if (letter < 'A' || letter > 'Z') {
					//for encoding to the clockwise
					letter = (char) (letter + 'Z' - 'A' + 1);
					encodedText[i] = letter;
				}
				else {
					encodedText[i] = letter;
				}
			}
			else {
				encodedText[i] = originalText[i];
			}
			
		}
		//to conver char[] array to a string
		String finalDecode = new String(encodedText);
		
		return finalDecode;
	}
	
	/**
	 * 
	 * @param array -  the array to search using binary method
	 * The array has to be sorted first in order to work.
	 * @param key - the specific integer you're looking for in the array.
	 * @return -1 if search is false, the index position of the first key found (wont return multiple keys if multiple exist).
	 */
	public static int binarySearch(int[] array, int key) {
		//sort first
		arraySort(array);
		
		boolean found = false;
		int low = 0, high = array.length -1;
		
		while (low <= high && !found) {
	        int mid = (low + high) / 2;//math to get to middle of array

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

	/**
	 * 
	 * @param array - the array to sort in ascending order.
	 */
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
	}
}
	