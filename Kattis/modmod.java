import java.util.Scanner;

public class modmod {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();
        while (numCases-- > 0) {
            int p = in.nextInt();
            int q = in.nextInt();
            int n = in.nextInt();
            long tot = 0;
            for (int i = 1; i <= n; i++) {
                tot = tot + ((p*i) % q);
            }
            System.out.println(tot);
        }
    }
}

/* 
3
2 7 2
1 4 5
3 8 10
*/


