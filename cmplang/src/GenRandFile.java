import java.io.PrintWriter;
import java.io.FileWriter;
import java.io.IOException;


class GenRandFile {
	public static void main(String[] args) {
		for(int i = 2; i <= 8; i++)
			genFile("bin/10e" + i + ".txt", (int)Math.pow(10.0,(double) i));
	}

	public static void genFile(String filename, int vals) {
		try {
			MTRandom mtr = new MTRandom();
			PrintWriter oStream = new PrintWriter(new FileWriter(filename));
			for (int i = 0; i < vals; i++)
				oStream.println(mtr.nextInt(Integer.MAX_VALUE));
			oStream.close();
		} catch(IOException ioe)
		{
			System.out.println("IOException caught.");
			ioe.printStackTrace();
		}
	}
}
