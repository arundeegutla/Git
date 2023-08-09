import java.util.Scanner;

public class sums {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numTris = in.nextInt();

        for (int i = 0; i < numTris; i++) {
            int tri = in.nextInt();
            int num = 0;

            for (int j = 1; j <= tri; j++) {
                num += j*getSums(1, j+1);
            }

            System.out.println(i+1 + " " + tri + " " + num);
        }
    }

    public static int getSums(int start , int tri) {
        if (start == tri) {
            return start;
        }
        return start+getSums(start+1, tri);
    }
}
