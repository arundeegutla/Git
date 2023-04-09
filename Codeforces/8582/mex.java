import java.util.Scanner;

public class mex {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();

        loop:while (numCases-->0) {
            int numNums = in.nextInt();
            int zeroes = 0;
            int ones = 0;
            for (int i = 0; i < numNums; i++) {
                int num = in.nextInt();
                if (num == 1)
                    ones++;
                if (num == 0)
                    zeroes++;
            }


            if ((numNums - zeroes) - zeroes >= -1) {
                System.out.println(0);
                continue loop;
            } else if (ones==0 || zeroes + ones < numNums) {
                System.out.println(1);
                continue loop;
            } else {
                System.out.println(2);
            }
            
        }
    }
}
