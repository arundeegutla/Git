import java.util.Scanner;

public class c {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();
        while (numCases-->0) {
            int m = in.nextInt();
            int oneBits = Integer.bitCount(m);
            int k = 1;
            while (Integer.bitCount((k+1)*m) < oneBits) {
                k+=m;
            }
            System.out.println(Integer.toBinaryString((k)*m));
        }
    }
}
