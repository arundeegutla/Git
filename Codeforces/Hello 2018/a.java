import java.util.Scanner;

/**
 * a
 */
public class a {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);


        int[] cheese = {1, 2, 4, 8, 16, 32, 64, 128, 256, 512, 1024, 2048, 4096, 8192, 16384, 32768, 65536, 131072, 262144, 524288, 1048576, 2097152, 4194304, 8388608, 16777216, 33554432, 67108864, 134217728};

        int n = in.nextInt();
        int m = in.nextInt();

        if (n >= 27) {
            System.out.println(m);
        } else {
            System.out.println(m % cheese[n]);
        }

    }
}