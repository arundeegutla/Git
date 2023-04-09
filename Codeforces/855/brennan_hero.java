import java.util.ArrayList;
import java.util.Arrays;
import java.util.PriorityQueue;
import java.util.Scanner;

public class c {

	public static void main(String[] args) {
		Scanner s = new Scanner(System.in);
		int t = s.nextInt();
		
		while (t-- > 0) {
			int n = s.nextInt();
			int[] arr = new int[n];

			PriorityQueue<Point> pq = new PriorityQueue<Point>();
			long res = 0;
            
			for (int i = 0; i < n; i++) {
				arr[i] = s.nextInt();

				if (arr[i] != 0) 
                    pq.add(new Point(arr[i], i));
				else if (!pq.isEmpty()) 
                    res += pq.poll().val;
			}

			System.out.println(res);
		}
	}
}

class Point implements Comparable<Point> {
	int val, idx;
	
	Point(int val, int idx) {
		this.val = val;
		this.idx = idx;
	}

	@Override
	public int compareTo(Point o) {
		return o.val - this.val;
	}
}
