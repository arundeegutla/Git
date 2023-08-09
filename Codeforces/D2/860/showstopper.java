import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Scanner;

/**
 * showstopper
 */
public class showstopper {

    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int numCases = in.nextInt();
        while (numCases-->0) {
            int numVals = in.nextInt();
            int[] arr1 = new int[numVals];
            int[] arr2 = new int[numVals];
            
            for (int i = 0; i < numVals; i++) {
                arr1[i] = in.nextInt();
            }
            for (int i = 0; i < numVals; i++) {
                arr2[i] = in.nextInt();
            }

            for (int i = 0; i+1 < numVals; i++) {

                if (arr1[i] > arr1[numVals - 1]) {
                    int temp = arr1[i];
                    arr1[i] = arr2[i];
                    arr2[i] = temp;

                }
                
                if (arr2[i] > arr2[numVals - 1]) {
                    int temp = arr2[i];
                    arr2[i] = arr1[i];
                    arr1[i] = temp;
                }
            }

            int max1 = arr1[0];
            int max2 = arr2[0];

            for (int i = 0; i+1 < numVals; i++) {
                max1 = Math.max(max1, arr1[i]);
                max2 = Math.max(max2, arr2[i]);
            }
            

            if (max1 <= arr1[numVals - 1] && max2 <= arr2[numVals - 1]) {
                System.out.println("yes");
            } else {
                System.out.println("no");
            }

        }
        
    }
}