import java.util.Scanner;

public class m {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int totalJudgest = in.nextInt();

        int givenJudegs = in.nextInt();

        int review = 0;

        for (int i = 0; i < givenJudegs; i++) {
            review += in.nextInt();
        }

        System.out.println(((review + (-3 * (totalJudgest - givenJudegs)))/(double)totalJudgest) + " " + ((review + (3 * (totalJudgest - givenJudegs)))/(double)totalJudgest));

        in.close();

    }
}
