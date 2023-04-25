import java.util.Scanner;
/**
 * haircut
 */
public class haircut {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int n = in.nextInt();

        int[] strands = new int[n];
        for (int i = 0; i < strands.length; i++)
            strands[i] = in.nextInt();


        BIT tree = new BIT(n+10);
        long[] count = new long[n+2];

        for (int strand : strands) {
            count[strand+1] += tree.atOrAbove(strand+2);
            tree.add(strand+1, 1);
        }

        System.out.println(0);
        for (int i = 1; i < n; i++) {
            count[i] += count[i-1];
            System.out.println(count[i]);
        }
    }
}

class BIT {

	public long[] cumfreq;

	// Do indexes 1 to n.
	public BIT(int n) {

		int size = 1;
		while (size < n) size <<= 1;
		n = size;

		cumfreq = new long[n+1];
	}

	// Uses 1 based indexing.
	public void add(int index, long value) {
		while (index < cumfreq.length) {
			cumfreq[index] += value;
			index += Integer.lowestOneBit(index);
		}
	}

	// Returns the sum of everything upto index.
	public long sum(int index) {
		long ans = 0;
		while (index > 0) {
			ans += cumfreq[index];
			index -= (Integer.lowestOneBit(index));
		}
		return ans;
	}

	// Use 1 based indexing.
	public long sum(int low, int high) {
		return sum(high) - sum(low-1);
	}

	// Return the total number of items in the BIT.
	public long all() {
		return sum(cumfreq.length-1);
	}

	// Return the total number of items in the BIT at or above index.
	public long atOrAbove(int index) {
		return all() - (index > 0 ? sum(index-1) : 0);
	}

}