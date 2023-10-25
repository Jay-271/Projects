package practice_9_21;
import java.io.*;
import java.util.Scanner;
public class herWriteFiles {

	public static void main(String[] args) {
		// TODO Auto-generated method stub
		String outFile = "files/herOutFile.txt";
		PrintWriter outputStream = null;
		try {
			//to append and not erase file FileOutputStream object w/ tue
			outputStream = new PrintWriter(new FileOutputStream(outFile, true));
		} catch(FileNotFoundException e) {
			System.out.println("Could not open output file.");
			System.exit(1);
		}
		
		int lineNumber = 1;
		for (int i = 0; i < args.length; i++) {
			Scanner inputStream = null;
			
			try {
				inputStream = new Scanner(new File(args[i]));
			}catch(FileNotFoundException e) {
				System.out.println("Cannot open file: " + args[i] + "\nContinuing...");
				continue;
			}
			//idk something wrong here boss
			while (inputStream.hasNextLine()) {
				outputStream.println(lineNumber + ". " + inputStream.hasNextLine());
			}
			inputStream.close();
		}
		
		outputStream.close();
		System.exit(0);
	}

}
