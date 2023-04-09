import java.util.Scanner;

public class candies {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        
        int numCases = in.nextInt();
        while (numCases-->0) {
            int numCandies = in.nextInt();
            long odd = 0;
            long even = 0;
            for (int i = 0; i < numCandies; i++) {
                int num = in.nextInt();
                if (num%2==0) {
                    even+=num;
                } else {
                    odd += num;
                }
            }

            System.out.println((even > odd) ? "yes" : "no");
        }
    }
}
