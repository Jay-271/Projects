package practice_9_21;
import java.io.File;
import java.io.FileNotFoundException;
import java.io.FileOutputStream;
import java.io.PrintWriter;
import java.util.Scanner;
//could also use import java.io* to get ALL the packages...

public class WriteFiles {
	/**
	 * this basically deletes the file "test.txt" and replaces it with whatever in the outStream.println has
	 * @param args
	 */
	
	/*
	public static void main(String[] args) {
		PrintWriter outStream = null;
		String filename = "test.txt";
		try {
			outStream = new PrintWriter(filename);
			outStream.println("Hi lol :)");
		} catch(FileNotFoundException e) {
			System.out.println("Cannot open file " + filename);
		} finally {
			outStream.close();
			System.exit(0);
		}
	} */
	
	
	//String filename = "test.txt";
	//in this case, test.txt already exists
	
	//Read: 
	/*Scanner inStream = null;
	try {
		inStream = new Scanner(new File(filename));
	} catch(FileNotFoundException e) {
		System.out.println("File not able to open: " + e.getMessage());
	}
	
	//append and/or ADD to a file
	PrintWriter outStream = null;
	
	try {
		outStream = new PrintWriter(new FileOutputStream(filename, true));
	}catch(FileNotFoundException e) {
		System.out.println("File not able to open: " + e.getMessage());
	}*/
	//////
	public static void main(String[] args) {

		
		
		File[] files = new File[3];
		File finalParts = new File("files/FinalParts.txt");
	
		Scanner keyInput = new Scanner(System.in);
		System.out.println("Please enter 3 file names!");
		files[0] = new File("files/" + args[0] + ".txt");
		System.out.println();
		files[1] = new File("files/" + args[1] + ".txt");
		System.out.println();
		files[2] = new File("files/" + args[2] + ".txt");
		
		for (int i = 0; i < 3; i++) {
			if (!files[i].exists()) {
				
				//make new file if it doesnt exist
				PrintWriter oStream = null;
				try {
					oStream = new PrintWriter(files[i]);
				} catch(FileNotFoundException e) {
					System.out.println("Cannot open file " + files[i]);
				}
				finally {
					oStream.close();
				}
			}
		}
		
		//make new file if it doesnt exist outside loop for final file
		PrintWriter oStream = null;
		try {
			oStream = new PrintWriter("files/FinalParts.txt");
		} catch(FileNotFoundException e) {
			System.out.println("Cannot open file " + finalParts);
		}
		
		//after all files are created start appending all to final file
			//this formats the files into 1, 2, 3... etc.
		Scanner inStream = null;
		for (int i = 0; i < files.length; i++) {
			oStream.print((i+1) + ". ");
			try {
				inStream = new Scanner(files[i]);
				while (inStream.hasNextLine()) {
					oStream.println(inStream.nextLine());
					}
			}catch(FileNotFoundException e) {
				System.out.println("File not able to open: " + e.getMessage());
			}
		}
		
		
		//just testing foreach loop (IT WORKS)
		/*
		try {
			oStream = new PrintWriter("files/FinalPartswithForeach.txt");
		} catch(FileNotFoundException e) {
			System.out.println("Cannot open file " + finalParts);
		}
		oStream.println("If this works then the foreach loop works\n");
		
		for(File i: files) {
			int j = 0; // counter for nums
			try {
				inStream  = new Scanner(i);
				oStream.println((j+1) + ". " + inStream.nextLine());
				
			}catch(FileNotFoundException e) {
				System.out.println("File not able to open: " + e.getMessage());
			}
			j++;
		}
		*/
		System.out.println("File created!");
		
		oStream.close();
		inStream.close();
		keyInput.close();
		
	}
}







