import java.util.Scanner;

import javax.swing.plaf.synth.SynthDesktopIconUI;

public class increasing {
    public static void main(String[] args) {
        Scanner in = new Scanner(System.in);
        int num = in.nextInt();
        int[] numArray = new int[num];
        for (int i = 0; i < num; i++) 
            numArray[i] = in.nextInt();
        long count = 0;
        for (int i = 0; i+1 < numArray.length; i++) {
            if (numArray[i] > numArray[i+1]) {
                count += numArray[i] - numArray[i+1];
                numArray[i+1] = numArray[i];
            }
        }
        System.out.println(count);
    }
}
