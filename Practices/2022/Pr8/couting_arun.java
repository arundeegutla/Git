import java.util.Scanner;


public class couting_arun {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        int numCards = in.nextInt();

        int[] cards = new int[numCards];

        for (int i = 0; i < numCards; i++) {
            cards[i] = in.nextInt();
        }


        int sum = 0;
        long min = Long.MAX_VALUE;
        int start = -1;
        int end = -1;

        for (int i = 0; i < numCards; i++) {

            sum += cards[i];

            if (sum > 0) {

                sum = 0;
                start = -1;

            } 

            if (sum < min) {

                if (start == -1) {
                    start = i;
                }

                min = sum;
                end = i;
            }   
            
        }


        System.out.println(start + " " + end);
        long count = 0;
        long total = 0;

        for (int i = 0; i < numCards; i++) {
            if (! (i >= start && i <= end )) {
                total += cards[i];
                count++;
            }
        }

        if (count > 0) {
            System.out.printf("%.9f\n", total/(double)count);
        } else {
            System.out.printf("%.9f\n", (double)0);

        }


    }
}
