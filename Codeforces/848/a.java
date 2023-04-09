import java.util.Scanner;

/**
 * a
 */
public class a {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();
        while (numCases-->0) {
            int numOf = in.nextInt();
            boolean hasNeg = false;
            boolean prevNeg = false;
            boolean done = false;
            int sum = 0;

            for (int i = 0; i < numOf; i++) {
                int num = in.nextInt();
                if (prevNeg && num < 0 && !done){
                    sum += 3;
                    done = true;
                }
                else sum += num;
                    
                if (num < 0){
                    prevNeg = true;
                    hasNeg = true;
                }
                else 
                    prevNeg = false;   
            }

            if (done) {
                System.out.println(sum);
            } else if (!hasNeg) {
                System.out.println(sum-4);
            } else {
                System.out.println(sum);
            }

        }
    }
}