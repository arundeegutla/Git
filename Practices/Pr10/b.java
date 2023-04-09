import java.util.Scanner;

public class b {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        long[] gifts = new long[1000001];
        long[] sums = new long[1000001];


        for (int i = 1; i < gifts.length; i++)
            gifts[i] = i + gifts[i-1];
        
        long add = 0;
        for (int i = 1; i <= 1000000; i++) {
            sums[i] = gifts[i] + add;
            add = sums[i];
        }

        int n;
        while ((n = in.nextInt()) != 0)
            System.out.println(sums[n]);
    }
}
