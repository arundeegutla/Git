import java.util.ArrayList;
import java.util.Arrays;
import java.util.Scanner;

public class c {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();
        while (numCases-->0) {
            int numNums = in.nextInt();
            int[] arr = new int[numNums];
            for (int i = 0; i < numNums; i++)
                arr[i]= in.nextInt();

            int prevAt = 0;
            int prevNum = 0;
            for (int i = 0; i < numNums; i++) {
                prevNum++;
                while (arr[prevAt]<prevNum && prevNum!=1) {
                    prevAt++;
                    prevNum--;
                }
                System.out.print(prevNum + (i==arr.length-1?"\n":" "));
            }

        }
    }
}
