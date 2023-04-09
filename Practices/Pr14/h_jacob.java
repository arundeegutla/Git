import java.util.Arrays;
import java.util.Scanner;

public class h_jacob
{
	static int numHPacks;
	static int numBPacks;
	static int[] hPacks;
	static int[] bPacks;
	static int[][] dpH;
	static int[][] dpB;
	
	public static void main(String[] args)
	{
		Scanner in = new Scanner(System.in);
		int hSum = 0;
		int bSum = 0;
		
		numHPacks = in.nextInt();
		hPacks = new int[numHPacks];
		for (int i = 0; i < numHPacks; i++)
		{
			hPacks[i] = in.nextInt();
			hSum += hPacks[i];
		}
		
		numBPacks = in.nextInt();
		bPacks = new int[numBPacks];
		for (int i = 0; i < numBPacks; i++)
		{
			bPacks[i] = in.nextInt();
			bSum += bPacks[i];
		}
		
		int maxCase = Math.min(hSum, bSum);
		
		dpH = new int[numHPacks][maxCase + 1];
		for (int[] e : dpH)
			Arrays.fill(e, -1);
		
		dpB = new int[numBPacks][maxCase + 1];
		for (int[] e : dpB)
			Arrays.fill(e, -1);
		
		int res = 10000;
		
		for (int i = 1; i <= maxCase; i++)
		{
//			System.out.println("GOH AT I = " + i + ": " + goH(0, i));
//			System.out.println("GOB AT I = " + i + ": " + goB(0, i));

			res = Math.min(res, goH(0, i) + goB(0, i));
		}
		
		if (res > 200)
			System.out.println("impossible");
		else
			System.out.println(res);
	}

	static int goH(int i, int k)
	{
		if (k == 0)
			return 0;
		
		if (i >= numHPacks || k < 0)
			return 10000;
		
		if (dpH[i][k] != -1)
			return dpH[i][k];
		
		int temp = Math.min(1 + goH(i + 1, k - hPacks[i]), goH(i + 1, k));
		dpH[i][k] = temp;
		return temp;
	}
	
	static int goB(int i, int k)
	{
		if (k == 0)
			return 0;
		
		if (i >= numBPacks || k < 0)
			return 10000;

		if (dpB[i][k] != -1)
			return dpB[i][k];
		
		int temp = Math.min(1 + goB(i + 1, k - bPacks[i]), goB(i + 1, k));
		dpB[i][k] = temp;
		return temp;
	}
}