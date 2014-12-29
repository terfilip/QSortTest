import java.io.File;
import java.io.PrintWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Scanner;


class Qsort {
	public static void main(String[] args) {
		try {
			if ((args.length < 1) || (args.length > 2)) {
				System.out.println("Usage java Qsort <powerOfTen> {if print}--print");
				System.exit(0);
			}
			final int IDX = Integer.parseInt(args[0]);
			final int ARRAY_LENGTH = powTen(IDX);
			String ifName = String.format("%s%d%s","10e",IDX, ".txt");
			String ofName = String.format("%s%d%s","10e",IDX, "sortedJava.txt");

			int[] a = new int[ARRAY_LENGTH];
			initArray(a, ifName);
			quicksort(a, 0, ARRAY_LENGTH - 1);
			//Used for testing
			if ((args.length == 2) && (args[1].equals("--print")))
				printArray(a, ofName);

			System.out.printf("Sorted %d integers in Java.\n",ARRAY_LENGTH);
		}
		catch(IOException ioe) {
			System.out.println("File not found");
			ioe.printStackTrace();
		}
	}

	public static void printArray(int[] a, String outFileName) throws IOException {
		PrintWriter oStream = new PrintWriter(outFileName, "UTF-8");
		for (int i = 0; i < a.length; i++)
			oStream.println(a[i]);
		oStream.close();
	}

	public static void initArray(int[] a, String inFileName) throws IOException {
		Scanner iStream = new Scanner(new File(inFileName));
		int i = 0;
		while(iStream.hasNextInt())
			a[i++] = iStream.nextInt();
		iStream.close();
	}

	public static void quicksort(int[] a, int left, int right) {
		if (left < right) {
			int pivotIdx = left + ((right - left)/2);
			int newPivotIdx = partition(a, left, right, pivotIdx);
			quicksort(a, left, newPivotIdx -1);
			quicksort(a, newPivotIdx + 1, right);
		}
	}

	public static int partition(int[] a, int left, int right, int pivotIdx) {
		int pivotVal = a[pivotIdx];
		swap(a, pivotIdx, right);
		int storeIdx = left;
		for(int i = left; i < right; i++)
			if(a[i] < pivotVal)
				swap(a, i, storeIdx++);
		swap(a, storeIdx, right);
		return storeIdx;
	}

	public static void swap(int[] a, int x, int y) {
		int tmp = a[x];
		a[x] = a[y];
		a[y] = tmp;
	}

	public static int powTen(int idx) {
		if (idx == 0)
			return 1;
		else
			return 10 * powTen(idx - 1);
	}
}
