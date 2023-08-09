import java.util.HashMap;
import java.util.HashSet;
import java.util.Scanner;

public class f {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int t = s.nextInt();
		while (t-- > 0) {
			int n = s.nextInt();
			HashMap<Integer, Integer> app = new HashMap<Integer, Integer>();
			for (int i = 0; i < n; i++) {
				int curr = s.nextInt();
				app.put(curr, app.getOrDefault(curr, 0) + 1);
			}
			int max = 0;
			for (int i = 0; i < n; i++) {
				int count = 0, currN = i + 1;
				HashSet<Integer> div = new HashSet<Integer>();
				div.add(1);
				div.add(currN);
				for (int j = 2; j * j <= currN; j++) {
					if (currN % j == 0) { div.add(j); div.add(currN / j); }
				}
				for (Integer d : div) {
					if (d <= n) count += app.getOrDefault(d, 0);
				}
				
				max = Math.max(max, count);
			}
			System.out.println(max);
		}
	}
}
