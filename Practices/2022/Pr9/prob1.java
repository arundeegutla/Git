import java.util.ArrayList;
import java.util.Collections;
import java.util.Scanner;

/**
 * prob1
 */
public class prob1 {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);

        long a = 0;
        long b = 0;
        long c = 0;
        long d = 0;
        long f = 0;
        double median = 0;
        long high = 0;

        ArrayList<Integer> scores = new ArrayList<>();

        int num = 0;

        while ((num = in.nextInt()) >= 0) {

            if (num >= 90) {
                a++;
            } else if(num >= 80){
                b++;
            }
            else if (num >= 70) {
                c++;
            }else if (num >= 60) {
                d++;
            }
            else {
                f++;
            }


            if (high < num) {
                high = num;
            }

            scores.add(num);
        }


        if (scores.size() > 1) {
            Collections.sort(scores);


            if (scores.size() % 2 == 0) {
                
                median = ((double)scores.get((scores.size()/2) - 1) + scores.get((scores.size()/2) + 1))/2;

            } else {
                median = scores.get((scores.size()/2));
            }
        }


        System.out.printf("Median = %.1f%%\n", median);
        System.out.println("High Score = " + high);
        System.out.println("As = " + a);
        System.out.println("Bs = " + b);
        System.out.println("Cs = " + c);
        System.out.println("Ds = " + d);
        System.out.println("Fs = " + f);
        

    }
}
